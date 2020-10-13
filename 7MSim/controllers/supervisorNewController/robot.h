#pragma once

using namespace webots;

struct Velocity
{
    int left;
    int right;
};

struct Point
{
    double x;
    double y;
};

struct RobotStruct
{
    int number;
    int connection;
    Point currentLocation;
    Velocity currentVelocity;
};
