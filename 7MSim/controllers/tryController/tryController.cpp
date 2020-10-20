#include <webots/Supervisor.hpp>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;

int main(int argc, char **argv) {
  Supervisor *supervisor = new Supervisor();
  
  int timeStep = (int)supervisor->getBasicTimeStep();
  
  Motor *leftMotor = supervisor->getMotor("leftMotor");
  Motor *rightMotor = supervisor->getMotor("rightMotor");  
 
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);
  
  leftMotor->setVelocity(0);
  rightMotor->setVelocity(0);
 
  while (supervisor->step(timeStep) != -1) {
    leftMotor->setVelocity(-10);
    rightMotor->setVelocity(-10);
  };

  delete leftMotor;
  delete rightMotor;
  
  delete supervisor;
  
  return 0;
}
