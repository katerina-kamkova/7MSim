#include <webots/Robot.hpp>
#include <webots/Supervisor.hpp>

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();

  const double firstLineStart = -2.75; 
  const double boundaries = 2;
  const int obstaclesNUmber = 7;
  
  Node *robots = new Node[obstaclesNUmber];
  Field *translations = new Field[obstaclesNUmber];
  Field *rotations = new Field[obstaclesNUmber];
  
  Field *transField = robot_1_0->getField("translation");
  Field *rotField = robot_1_0->getField("rotation");
  
  for (int i = 0; i < obstaclesNUmber; i++)
  {
    robots[i] = supervisor->getFromDef("robot_2_" + i);
    translations[i] = robots->getField("translation");
    rotations[i] = robots->getField("rotation");
  }
  
  for (int i = 0; i < obstaclesNUmber; i ++)
  {
    const double vector[3] = {0, 0, 0}; 
    translations[i]->setSFVec3f(vector);
  }
  
  while (robot->step(timeStep) != -1) {
    
    
    
  };

  delete robot;
  return 0;
}
