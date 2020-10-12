#include <webots/Robot.hpp>
#include <webots/Camera.hpp>

using namespace webots;

int main(int argc, char **argv) { 
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  
  Camera *camera = robot->getCamera("camera");
  camera->enable(1);    
    
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {

  };

  delete camera;
  delete robot;
  return 0;
}
