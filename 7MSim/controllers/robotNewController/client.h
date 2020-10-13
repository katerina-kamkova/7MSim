#pragma once
#include "world_data.pb.h"

class Client{
public:
  Client(bool tcp, int port);
  void sendNumber(int number) const;
  void sendVelocity(protocol::WheelsVelocity velocity) const;
  protocol::WheelsVelocity getVelocity() const;

private:
  int sock;
};
