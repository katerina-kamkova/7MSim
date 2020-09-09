#pragma once

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
    double rotation;
    Point location;
    Velocity velocity;
};
