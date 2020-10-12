#pragma once
#include "robot.h"

class Client{
public:
  Client(bool tcp, int port);
  void sendNumber(int number) const;
  Velocity getCommand() const;

private:
  int sock;
};
