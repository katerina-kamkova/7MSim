//
// Created by yarkoe on 03.10.2020.
//

#include <vector>
#include <cmath>
#include "ObstacleAvoidance.h"

protocol::WheelsVelocity ObstacleAvoidance::dwa(const protocol::WorldData& worldData)
{
    auto bestBenefit = -100000;

    protocol::WheelsVelocity bestWheelsVelocity;
    bestWheelsVelocity.set_leftwheelvelocity(worldData.robotdata().wheelsvelocity().leftwheelvelocity()) ;
    bestWheelsVelocity.set_rightwheelvelocity(worldData.robotdata().wheelsvelocity().rightwheelvelocity());

    std::vector<double> lMutls = MULTS, rMults = MULTS;

    double currDistanceToBall = CalculateDistanceBetween(worldData.robotdata().position().coord(), worldData.ballcoord());

    for (auto lMult : lMutls)
    {
        for (auto rMult : rMults)
        {
            protocol::WheelsVelocity possibleWheelsVelocity;
            possibleWheelsVelocity.set_leftwheelvelocity(worldData.robotdata().wheelsvelocity().leftwheelvelocity() - lMult * DELTA);
            possibleWheelsVelocity.set_rightwheelvelocity(worldData.robotdata().wheelsvelocity().rightwheelvelocity() - rMult * DELTA);

            if (possibleWheelsVelocity.leftwheelvelocity() > ROBOT_MAX_VELOCITY or possibleWheelsVelocity.leftwheelvelocity() < -ROBOT_MAX_VELOCITY or
                possibleWheelsVelocity.rightwheelvelocity() > ROBOT_MAX_VELOCITY or possibleWheelsVelocity.rightwheelvelocity() < -ROBOT_MAX_VELOCITY) continue;

            protocol::Position predictRobotPosition = CalculateNewPosition(possibleWheelsVelocity,
                                                                      worldData.robotdata().position());

            double predictDistanceToBall = CalculateDistanceBetween(predictRobotPosition.coord(), worldData.ballcoord());
            double robotBallDistanceDifference = currDistanceToBall - predictDistanceToBall;
            double distanceBenefit = FORWARD_WEIGHT * robotBallDistanceDifference;

            double distanceToClosestObstacle = CalculateClosestObstacleDistance(predictRobotPosition.coord(), worldData.obstaclecoords());
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

protocol::Position ObstacleAvoidance::CalculateNewPosition(const protocol::WheelsVelocity& velocity, const protocol::Position& position)
{
    protocol::Coord returnCoord;
    protocol::Position returnPosition;

    if (std::abs(velocity.leftwheelvelocity() - velocity.rightwheelvelocity()) < 0.001)
    {
        // forward motion
        returnCoord.set_x(position.coord().x() + velocity.rightwheelvelocity() * TAU * cos(position.theta()));
        returnCoord.set_y(position.coord().y() + velocity.rightwheelvelocity() * TAU * sin(position.theta()));

        returnPosition.set_theta(position.theta());
    }
    else if (std::abs(velocity.leftwheelvelocity() + velocity.rightwheelvelocity()) < 0.001)
    {
        // rotation motion
        returnCoord.set_x(position.coord().x());
        returnCoord.set_y(position.coord().y());

        returnPosition.set_theta(position.theta() + ((velocity.rightwheelvelocity() - velocity.leftwheelvelocity()) * TAU / ROBOT_WIDTH));
    }
    else
    {
        double R = ROBOT_WIDTH / 2. * (velocity.rightwheelvelocity() + velocity.leftwheelvelocity())
                   / (velocity.rightwheelvelocity() - velocity.leftwheelvelocity());

        double deltaTheta = (velocity.rightwheelvelocity() - velocity.rightwheelvelocity()) * TAU / ROBOT_WIDTH;

        returnCoord.set_x(position.coord().x() + R * (sin(deltaTheta + TAU) - sin(TAU)));
        returnCoord.set_y(position.coord().y() - R * (cos(deltaTheta + TAU) - cos(TAU)));


        returnPosition.set_theta(position.theta() + deltaTheta);
    }

    // I forget how it works. maybe returnCoord will be lost after method end
    // TODO: DEBUG
    returnPosition.set_allocated_coord(&returnCoord);

    return returnPosition;
}

double ObstacleAvoidance::CalculateClosestObstacleDistance(const protocol::Coord& robotCoord, const google::protobuf::RepeatedPtrField<protocol::Coord>& obstacleCoords) {
    double closestDistance = 10000000.;

    for (const auto& obstacleCoord : obstacleCoords)
    {
        double curDistance = CalculateDistanceBetween(robotCoord, obstacleCoord);

        curDistance -= OBSTACLE_RADIUS + ROBOT_RADIUS;

        if (closestDistance > curDistance)
        {
            closestDistance = curDistance;
        }
    }

    return closestDistance;
}

double ObstacleAvoidance::CalculateDistanceBetween(const protocol::Coord& coord1, const protocol::Coord& coord2) {
    return sqrt(pow(coord1.x() - coord2.x(), 2)+ pow(coord1.y() - coord2.y(), 2));
}
