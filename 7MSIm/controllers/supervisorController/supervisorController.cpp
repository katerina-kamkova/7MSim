#include <webots/Robot.hpp>
#include <webots/Supervisor.hpp>

#include "robot.h"
#include "client.h"
#include "client.cpp"

using namespace webots;

int main(int argc, char **argv) {
  Supervisor *supervisor = new Supervisor();
  int timeStep = (int)supervisor->getBasicTimeStep();
  
  auto client = new Client(true, 7777);
  client->sendNumber(0);
  
  Node *robot_1_0 = supervisor->getFromDef("robot_1_0");
  Field *transField = robot_1_0->getField("translation");
  Field *rotField = robot_1_0->getField("rotation");

  while (supervisor->step(timeStep) != -1) {
    client->sendData(100, transField, rotField);
  };
  
  delete client;
  delete supervisor;
  return 0;
}
