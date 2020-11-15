#pragma once

#include "world_data.pb.h"
#include "robot.h"

class Server{
public:
  Server (bool tcp, int port);
  RobotStruct connectClient() const;
  protocol::WheelsVelocity getVelocity(int connection);

private:
  int sock;
};

