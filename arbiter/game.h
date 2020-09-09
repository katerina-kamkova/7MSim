#pragma once
#include <vector>
#include <map>
#include "robot.h"
#include "server.h"

class Game{
public:
    ~Game();
    std::map<int, RobotStruct> robots;
    void Run();
};
