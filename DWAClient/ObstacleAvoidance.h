//
// Created by yarkoe on 03.10.2020.
//

#ifndef DWACLIENT_OBSTACLEAVOIDANCE_H
#define DWACLIENT_OBSTACLEAVOIDANCE_H

#include <vector>
#include "WorldStructures.h"


class ObstacleAvoidance {
public:
    static WheelsVelocity dwa(const WorldData& worldData);
private:
    static RobotPosition CalculateNewPosition(WheelsVelocity velocity, RobotPosition position);
    static double CalculateClosestObstacleDistance(Coord robotCoord, const std::vector<Coord>& obstacleCoords);
};

const int OBSTACLE_RADIUS = 1;
const int ROBOT_RADIUS = 1;
const int ROBOT_WIDTH = ROBOT_RADIUS * 2;
const int ROBOT_MAX_VELOCITY = 1;
const int ROBOT_MAX_ACCELERATION = 1;
const int FORWARD_WEIGHT = 200;
const int OBSTACLE_WEIGHT = 6666;
const double DT = 0.1;
const double TAU = DT * 7;
const double DELTA = ROBOT_MAX_ACCELERATION * DT;
const std::vector<double> MULTS = {-5, -3, -1, 0, 1, 3, 5};


#endif //DWACLIENT_OBSTACLEAVOIDANCE_H
