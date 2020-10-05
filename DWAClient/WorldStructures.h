//
// Created by yarkoe on 03.10.2020.
//

#ifndef DWACLIENT_WORLDSTRUCTURES_H
#define DWACLIENT_WORLDSTRUCTURES_H

#endif //DWACLIENT_WORLDSTRUCTURES_H

#include <vector>

struct Coord
{
    double x;
    double y;
};

struct RobotPosition
{
    Coord coord;
    double theta;
};

struct WheelsVelocity
{
    double leftWheelVelocity;
    double rightWheelVelocity;
};

struct RobotData
{
    RobotPosition robotPosition;
    WheelsVelocity wheelsVelocity;
};

struct WorldData
{
    RobotData robotData{};
    std::vector<Coord> obstacleCoords;
    Coord ballCoord{};
};