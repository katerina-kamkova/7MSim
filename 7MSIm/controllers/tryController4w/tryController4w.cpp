#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  
  Motor *w1 = robot->getMotor("wheel1");
  Motor *w2 = robot->getMotor("wheel2");  
  Motor *w3 = robot->getMotor("wheel3");
  Motor *w4 = robot->getMotor("wheel4");
 
  w1->setPosition(INFINITY);
  w2->setPosition(INFINITY);
  w3->setPosition(INFINITY);
  w4->setPosition(INFINITY);
 
  w1->setVelocity(29);
  w2->setVelocity(14);
  w3->setVelocity(29);
  w4->setVelocity(14);
  
  //int counter = 0;
  //int vel = 1;
  while (robot->step(timeStep) != -1) {
    /*if (counter % 100000 == 0)
    {
      w2->setVelocity(vel);
      w4->setVelocity(vel);
      vel ++;
    }
    
    if (w2->getVelocity() == 20)
    {
      vel = 0;
    }*/
  };

  delete w1;
  delete w2;
  delete w3;
  delete w4;
  
  delete robot;
  
  return 0;
}
