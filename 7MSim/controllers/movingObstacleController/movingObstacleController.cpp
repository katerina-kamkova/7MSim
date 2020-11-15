#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  
  int timeStep = (int)robot->getBasicTimeStep();
  
  Motor *leftMotor = robot->getMotor("leftMotor");
  Motor *rightMotor = robot->getMotor("rightMotor");  
 
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);
  
  leftMotor->setVelocity(20);
  rightMotor->setVelocity(20);
 
  while (robot->step(timeStep) != -1) {
    
  };

  delete leftMotor;
  delete rightMotor;
  
  delete robot;
  
  return 0;
}

