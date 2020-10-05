//
// Created by yarkoe on 03.10.2020.
//

#include <vector>
#include <cmath>
#include "ObstacleAvoidance.h"

WheelsVelocity ObstacleAvoidance::dwa(const WorldData& worldData)
{
    auto bestBenefit = -100000;

    WheelsVelocity bestWheelsVelocity {
            .leftWheelVelocity = worldData.robotData.wheelsVelocity.leftWheelVelocity,
            .rightWheelVelocity = worldData.robotData.wheelsVelocity.rightWheelVelocity
    };

    std::vector<double> lMutls = MULTS, rMults = MULTS;

    double currDistanceToBall = sqrt(pow(worldData.robotData.robotPosition.coord.x - worldData.ballCoord.x, 2)
                                     + pow(worldData.robotData.robotPosition.coord.y - worldData.ballCoord.y, 2));

    for (auto lMult : lMutls)
    {
        for (auto rMult : rMults)
        {
            WheelsVelocity possibleWheelsVelocity{
                    .leftWheelVelocity = worldData.robotData.robotPosition.coord.x - lMult * DELTA,
                    .rightWheelVelocity = worldData.robotData.robotPosition.coord.y - rMult * DELTA
            };

            if (possibleWheelsVelocity.leftWheelVelocity > ROBOT_MAX_VELOCITY or possibleWheelsVelocity.leftWheelVelocity < -ROBOT_MAX_VELOCITY or
                possibleWheelsVelocity.rightWheelVelocity > ROBOT_MAX_VELOCITY or possibleWheelsVelocity.rightWheelVelocity < -ROBOT_MAX_VELOCITY) continue;

            RobotPosition predictRobotPosition = CalculateNewPosition(possibleWheelsVelocity,
                                                                      worldData.robotData.robotPosition);

            double predictDistanceToBall = sqrt(pow(predictRobotPosition.coord.x - worldData.ballCoord.x, 2) + pow(predictRobotPosition.coord.y - worldData.ballCoord.y, 2));
            double robotBallDistanceDifference = currDistanceToBall - predictDistanceToBall;
            double distanceBenefit = FORWARD_WEIGHT * robotBallDistanceDifference;

            double distanceToClosestObstacle = CalculateClosestObstacleDistance(predictRobotPosition.coord, worldData.obstacleCoords);
            double obstacleBenefit = 0.;
            if (distanceToClosestObstacle < ROBOT_WIDTH)
            {
                obstacleBenefit = OBSTACLE_WEIGHT * (ROBOT_WIDTH - distanceToClosestObstacle);
            }

            double predictBenefit = distanceBenefit - obstacleBenefit;
            if (predictBenefit > bestBenefit)
            {
                bestBenefit = predictBenefit;
                bestWheelsVelocity = possibleWheelsVelocity;
            }
        }
    }

    return bestWheelsVelocity;
}

RobotPosition ObstacleAvoidance::CalculateNewPosition(WheelsVelocity velocity, RobotPosition position) {
    if (std::abs(velocity.leftWheelVelocity - velocity.rightWheelVelocity) < 0.001)
    {
        // forward motion
        return RobotPosition {
                .coord = Coord {
                        .x = position.coord.x + velocity.rightWheelVelocity * TAU * cos(position.theta),
                        .y = position.coord.y + velocity.rightWheelVelocity * TAU * sin(position.theta)
                },
                .theta = position.theta
        };
    }
    else if (std::abs(velocity.leftWheelVelocity + velocity.rightWheelVelocity) < 0.001)
    {
        // rotation motion
        return RobotPosition {
                .coord = Coord {
                        .x = position.coord.x,
                        .y = position.coord.y
                },
                .theta = position.theta + ((velocity.rightWheelVelocity - velocity.leftWheelVelocity) * TAU / ROBOT_WIDTH)

        };
    }
    else
    {
        double R = ROBOT_WIDTH / 2. * (velocity.rightWheelVelocity + velocity.leftWheelVelocity)
                   / (velocity.rightWheelVelocity - velocity.leftWheelVelocity);

        double deltaTheta = (velocity.rightWheelVelocity - velocity.rightWheelVelocity) * TAU / ROBOT_WIDTH;

        return RobotPosition {
                .coord = Coord {
                        .x = position.coord.x + R * (sin(deltaTheta + TAU) - sin(TAU)),
                        .y = position.coord.y - R * (cos(deltaTheta + TAU) - cos(TAU))
                },
                .theta = position.theta + deltaTheta
        };
    }
}

double ObstacleAvoidance::CalculateClosestObstacleDistance(Coord robotCoord, const std::vector<Coord> &obstacleCoords) {
    double closestDistance = 10000000.;

    for (auto obstacleCoord : obstacleCoords)
    {
        double curDistance = sqrt(pow(robotCoord.x - obstacleCoord.x, 2) + pow(robotCoord.y - obstacleCoord.y, 2));

        curDistance -= OBSTACLE_RADIUS + ROBOT_RADIUS;

        if (closestDistance > curDistance)
        {
            closestDistance = curDistance;
        }
    }

    return closestDistance;
}
