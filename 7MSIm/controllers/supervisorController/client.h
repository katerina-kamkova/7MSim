#pragma once
#include "robot.h"

class Client{
public:
  Client(bool tcp, int port);
  void sendNumber(int number) const;
  void sendData(int number, Field* transField, Field* rotField);

private:
  int sock;
};
