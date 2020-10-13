#include <webots/Supervisor.hpp>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

using namespace webots;

int main(int argc, char **argv) {
  //Robot *robot = new Robot();
  Supervisor *sup = new Supervisor();
  
  int timeStep = (int)sup->getBasicTimeStep();
  
  Motor *w1 = sup->getMotor("wheel1");
  Motor *w2 = sup->getMotor("wheel2");  
 
  w1->setPosition(INFINITY);
  w2->setPosition(INFINITY);
 
  w1->setVelocity(58);
  w2->setVelocity(28);
  
  Node *rn = sup->getFromDef("rn");
  Field *trans = rn->getField("translation");
  
  int counter = 0;
  //int vel = 1;
  while (sup->step(timeStep) != -1) {
    counter++;
    if (counter == 10)
    {
      const double INITIAL[3] = {2.03, 0.0675, 1.02};
      trans->setSFVec3f(INITIAL);
    }
  
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
  
  delete sup;
  
  return 0;
}
