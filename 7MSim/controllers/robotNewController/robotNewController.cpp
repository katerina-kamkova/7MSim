#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include "world_data.pb.h"

#include "client.h"
#include "client.cpp"

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  
  Motor *leftMotor = robot->getMotor("leftMotor");
  Motor *rightMotor = robot->getMotor("rightMotor"); 
  
  Client *sendVelClient = new Client(true, 7776);
  Client *getVelClient = new Client(true, 7777);
  
  while (robot->step(timeStep) != -1) {
    protocol::WheelsVelocity velocity;
    velocity.set_leftwheelvelocity((int)leftMotor->getVelocity());
    velocity.set_rightwheelvelocity((int)rightMotor->getVelocity());
    sendVelClient->sendVelocity(velocity);
    
    protocol::WheelsVelocity newVelocity = getVelClient->getVelocity();
    leftMotor->setVelocity((double)velocity.leftwheelvelocity());
    rightMotor->setVelocity((double)velocity.rightwheelvelocity()); 
  };

  delete robot;
  return 0;
}
