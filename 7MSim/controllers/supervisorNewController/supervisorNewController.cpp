#include <webots/Supervisor.hpp>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

#include <iostream>

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
  std::cout << "HI1" << std::endl;
  Client *client = new Client(true, 4343);                      // соединение с SSL-vision/game
  std::cout << "HI2" << std::endl;
  Node *actor = supervisor->getFromDef("actor");                // поля робота
  Field *actorTrans = actor->getField("translation");
  Field *actorRot = actor->getField("rotation");;
    
  int n = 7;                                                    // поля препятствий
  
  Field *trans1 = supervisor->getFromDef("obst1")->getField("translation");
  Field *trans2 = supervisor->getFromDef("obst2")->getField("translation");
  Field *trans3 = supervisor->getFromDef("obst3")->getField("translation");
  Field *trans4 = supervisor->getFromDef("obst4")->getField("translation");
  Field *trans5 = supervisor->getFromDef("obst5")->getField("translation");
  Field *trans6 = supervisor->getFromDef("obst6")->getField("translation");
  Field *trans7 = supervisor->getFromDef("obst7")->getField("translation");
  
  Field *ballTrans = supervisor->getFromDef("ball")->getField("translation");
  
  /*for (int i = 0; i < n; i ++)  {
    robots[i] = supervisor->getFromDef("obst" + (i + 1));
    trans[i] = robots[i]->getField("translation");
  }*/
  std::cout << "HI3" << std::endl;
  while (supervisor->step(timeStep) != -1) {
    protocol::WorldData *worldData = new protocol::WorldData();
    
    protocol::Coord *actorCoord = new protocol::Coord();
    const double *translation = actorTrans->getSFVec3f();
    actorCoord->set_x(translation[0]);
    actorCoord->set_y(translation[2]);
    
    protocol::Position *actorPos = new protocol::Position();
    actorPos->set_allocated_coord(actorCoord);
    const double *rot = actorRot->getSFRotation();
    actorPos->set_theta(rot[3] - 1.57);
    
    protocol::WheelsVelocity *actorVelocity = new protocol::WheelsVelocity();
    actorVelocity->set_leftwheelvelocity(leftMotor->getVelocity() / 100.0);
    actorVelocity->set_leftwheelvelocity(rightMotor->getVelocity() / 100.0);
    
    protocol::RobotData *actorData = new protocol::RobotData();
    actorData->set_allocated_position(actorPos);
    actorData->set_allocated_wheelsvelocity(actorVelocity);
    worldData->set_allocated_robotdata(actorData); 
        
    /*for (int i = 1; i < n; i++){
      protocol::Coord *obstCoord = worldData.add_obstaclecoords();
      const double *obstTranslation = trans[i]->getSFVec3f();
      obstCoord->set_x(obstTranslation[0]);
      obstCoord->set_y(obstTranslation[2]);
    }*/
    
    protocol::Coord *obstCoord1 = worldData->add_obstaclecoords();
    const double *obstTranslation1 = trans1->getSFVec3f();
    obstCoord1->set_x(obstTranslation1[0]);
    obstCoord1->set_y(obstTranslation1[2]);
    
    protocol::Coord *obstCoord2 = worldData->add_obstaclecoords();
    const double *obstTranslation2 = trans2->getSFVec3f();
    obstCoord2->set_x(obstTranslation2[0]);
    obstCoord2->set_y(obstTranslation2[2]);
      
    protocol::Coord *obstCoord3 = worldData->add_obstaclecoords();
    const double *obstTranslation3 = trans3->getSFVec3f();
    obstCoord3->set_x(obstTranslation3[0]);
    obstCoord3->set_y(obstTranslation3[2]);
    
    protocol::Coord *obstCoord4 = worldData->add_obstaclecoords();
    const double *obstTranslation4 = trans4->getSFVec3f();
    obstCoord4->set_x(obstTranslation4[0]);
    obstCoord4->set_y(obstTranslation4[2]);
    
    protocol::Coord *obstCoord5 = worldData->add_obstaclecoords();
    const double *obstTranslation5 = trans5->getSFVec3f();
    obstCoord5->set_x(obstTranslation5[0]);
    obstCoord5->set_y(obstTranslation5[2]);
    
    protocol::Coord *obstCoord6 = worldData->add_obstaclecoords();
    const double *obstTranslation6 = trans6->getSFVec3f();
    obstCoord6->set_x(obstTranslation6[0]);
    obstCoord6->set_y(obstTranslation6[2]);
    
    protocol::Coord *obstCoord7 = worldData->add_obstaclecoords();
    const double *obstTranslation7 = trans7->getSFVec3f();
    obstCoord7->set_x(obstTranslation7[0]);
    obstCoord7->set_y(obstTranslation7[2]);
    
    protocol::Coord *ballCoord = new protocol::Coord();
    const double *ballTranslation = ballTrans->getSFVec3f();
    ballCoord->set_x(ballTranslation[0]);
    ballCoord->set_y(ballTranslation[2]);
    worldData->set_allocated_ballcoord(ballCoord);
      
        
    std::cout << "HI4" << std::endl;
    
    client->sendWorldData(worldData);
    
    protocol::WheelsVelocity newVelocity = client->getNewVelocity();
    
    std::cout << "HI6" << std::endl;
    
    std::cout<<newVelocity.leftwheelvelocity()<<std::endl;
    std::cout<<newVelocity.rightwheelvelocity()<<std::endl;
    
    leftMotor->setVelocity(newVelocity.leftwheelvelocity());
    rightMotor->setVelocity(newVelocity.rightwheelvelocity());
    
    leftMotor->setVelocity(newVelocity.leftwheelvelocity() * (-1));
    rightMotor->setVelocity(newVelocity.rightwheelvelocity() * (-1));
    std::cout << "HI6" << std::endl;
  };

  delete supervisor;
  return 0;
}
