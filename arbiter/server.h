#pragma once

#include "robot.h"

class Server{
public:
    Server (bool tcp, int port);
    RobotStruct connectClient() const;
    void getData(int connection, std::map<int, RobotStruct>& robots);
    static void sendData(std::map<int, RobotStruct>& robots) ;

private:
    int sock;
};

