#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  
  Motor *leftMotor = robot->getMotor("leftMotor");
  Motor *rightMotor = robot->getMotor("rightMotor");
 
  leftMotor->setVelocity(10);
  rightMotor->setVelocity(10);
 
  leftMotor->setPosition(1000.0);
  rightMotor->setPosition(1000.0);
  
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    
  };

  delete robot;
  return 0;
}
