#include <webots/Supervisor.hpp>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

#include "client.cpp"

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
  
  Client *client = new Client(true, 7777);                      // соединение с SSL-vision/game
  
  Node *actor = supervisor->getFromDef("actor");                // поля робота
  Field *actorTrans = actor->getField("translation");
  Field *actorRot = actor->getField("rotation");;
    
  int n = 7;                                                    // поля препятствий
  Node *robots[n];
  Field *trans[n];
  
  for (int i = 0; i < n; i ++)  {
    robots[i] = supervisor->getFromDef("obst" + (i + 1));
    trans[i] = robots[i]->getField("translation");
  }
  
  while (supervisor->step(timeStep) != -1) {
    protocol::WorldData worldData;
    
    protocol::Coord actorCoord;
    const double *translation = actorTrans->getSFVec3f();
    actorCoord.set_x(translation[0]);
    actorCoord.set_y(translation[2]);
    
    protocol::Position actorPos;
    actorPos.set_allocated_coord(&actorCoord);
    const double *rot = actorRot->getSFRotation();
    actorPos.set_theta(rot[3] - 1.57);
    
    protocol::WheelsVelocity actorVelocity;
    actorVelocity.set_leftwheelvelocity((int)leftMotor->getVelocity());
    actorVelocity.set_leftwheelvelocity((int)rightMotor->getVelocity());
    
    protocol::RobotData actorData;
    actorData.set_allocated_position(&actorPos);
    actorData.set_allocated_wheelsvelocity(&actorVelocity);
    worldData.set_allocated_robotdata(&actorData);
        
    for (int i = 1; i < n; i++){
      protocol::Coord *obstCoord = worldData.add_obstaclecoords();
      const double *obstTranslation = trans[i]->getSFVec3f();
      obstCoord->set_x(obstTranslation[0]);
      obstCoord->set_y(obstTranslation[2]);
    }    
    
    client->sendWorldData(worldData);
    protocol::WheelsVelocity newVelocity;
    client->getNewVelocity(&newVelocity);
    
    leftMotor->setVelocity((double)newVelocity.leftwheelvelocity());
    rightMotor->setVelocity((double)newVelocity.rightwheelvelocity());
  };

  delete supervisor;
  return 0;
}
