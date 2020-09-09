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
    client->sendData(101, transField, rotField);
    //const double *translation = transField->getSFVec3f();
    //const double *rotation = rotField->getSFRotation();
  //std::cout << translation[0] << std::endl;
  //std::cout << rotation[3] << std::endl;
  //std::cout << translation[2] << std::endl;  
  };
  
  delete client;
  delete supervisor;
  return 0;
}
