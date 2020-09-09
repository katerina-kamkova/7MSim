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
 
  leftMotor->setVelocity(10);
  rightMotor->setVelocity(0);
  int counter = 0;
  
  while (robot->step(timeStep) != -1) {
    while (counter < 100)
    {
      rightMotor->setVelocity(counter);
      counter ++;
    }
  };

  delete rightMotor;
  delete leftMotor;
  delete robot;
  
  return 0;
}