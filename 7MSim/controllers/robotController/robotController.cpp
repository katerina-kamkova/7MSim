#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

#include "robot.h"
#include "client.h"
#include "client.cpp"

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  
  Motor *leftMotor = robot->getMotor("leftMotor");
  Motor *rightMotor = robot->getMotor("rightMotor");
 
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);
 
  leftMotor->setVelocity(-26);
  rightMotor->setVelocity(-30);
  
  auto client = new Client(true, 7777);
  client->sendNumber(100);
   
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    Velocity newVelocity = client->getCommand();
    
    leftMotor->setVelocity(newVelocity.left);
    rightMotor->setVelocity(newVelocity.right); 
    
    std::cout << leftMotor->getVelocity() << std::endl << rightMotor->getVelocity() << std::endl;   
  };

  delete client;
  delete rightMotor;
  delete leftMotor;
  delete robot;
  
  return 0;
}