#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  
  Motor *w1 = robot->getMotor("wheel1");
  Motor *w2 = robot->getMotor("wheel2");  
 
  w1->setPosition(INFINITY);
  w2->setPosition(INFINITY);
 
  w1->setVelocity(58);
  w2->setVelocity(28);
  
  int counter = 0;
  //int vel = 1;
  while (robot->step(timeStep) != -1) {
    //if (counter % 100000 == 0)
    //{
      //w2->setVelocity(vel);
      //vel ++;
    //}
    
    //if (w2->getVelocity() == 10)
    //{
      //vel = 0;
    //}
    /*counter ++;
    if (counter > 10){
    w1->setVelocity(39);
    w2->setVelocity(28);}*/
  };

  delete w1;
  delete w2;
  
  delete robot;
  
  return 0;
}
