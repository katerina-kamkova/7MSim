#pragma once
#include "world_data.pb.h"

class Client{
public:
  Client(bool tcp, int port);
  void sendWorldData(protocol::WorldData worldData) const;
  void getNewVelocity(protocol::WheelsVelocity *newVelocity) const;
  
private:
  int sock;
};
