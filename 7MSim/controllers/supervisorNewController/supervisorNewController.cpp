#include <webots/Supervisor.hpp>
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

#include <iostream>

#include "client.cpp"

using namespace webots;

const double length = 3;
const double width = 2;

const double robotRadius = 0.0675;
const double ballRadius = 0.02;

const int n = 7;

double randInRange (double a, double b){
  return (double)std::rand() * (b - a) / RAND_MAX + a;
}

int main(int argc, char **argv) {
  Supervisor *supervisor = new Supervisor();
  int timeStep = (int)supervisor->getBasicTimeStep();
  
  Motor *leftMotor = supervisor->getMotor("leftMotor");
  Motor *rightMotor = supervisor->getMotor("rightMotor");  
 
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);
 
  leftMotor->setVelocity(0);
  rightMotor->setVelocity(0);
  
  Client *client = new Client(true, 4343);
  
  Node *actor = supervisor->getFromDef("actor");                // поля робота
  Field *actorTrans = actor->getField("translation");
  Field *actorRot = actor->getField("rotation");
  
  Field *translations[n];
  Field *rotations[n];
  for (int i = 0; i < n; i++) {
    translations[i] = supervisor->getFromDef("obst" + std::to_string(i + 1))->getField("translation");
    const double randomPosition[3] = {randInRange(- length + 0.1, length - 0.1), 0.0675, randInRange(- width + 0.1, width - 0.1)};
    translations[i]->setSFVec3f(randomPosition);
    
    rotations[i] = supervisor->getFromDef("obst" + std::to_string(i + 1))->getField("rotation");
    double newRotation[4];
    newRotation[0] = 0.0;
    newRotation[1] = 1.0;
    newRotation[2] = 0.0;
    newRotation[3] = randInRange(0, M_PI * 2);
    
    rotations[i]->setSFRotation(newRotation);
    
    //robot->resetPhysics();
  }    
 
  Field *ballTrans = supervisor->getFromDef("ball")->getField("translation");
  
  while (supervisor->step(timeStep) != -1) {
    protocol::WorldData *worldData = new protocol::WorldData();
    
    protocol::Coord *actorCoord = new protocol::Coord();
    const double *translation = actorTrans->getSFVec3f();
    actorCoord->set_x(translation[0]);
    actorCoord->set_y(translation[2] * (-1));
    
    protocol::Position *actorPos = new protocol::Position();
    actorPos->set_allocated_coord(actorCoord);
    const double *rot = actorRot->getSFRotation();
    actorPos->set_theta(rot[3] - (M_PI / 2));
    
    protocol::WheelsVelocity *actorVelocity = new protocol::WheelsVelocity();
    actorVelocity->set_leftwheelvelocity(leftMotor->getVelocity() / 50.0);
    actorVelocity->set_leftwheelvelocity(rightMotor->getVelocity() / 50.0);
    
    protocol::RobotData *actorData = new protocol::RobotData();
    actorData->set_allocated_position(actorPos);
    actorData->set_allocated_wheelsvelocity(actorVelocity);
    worldData->set_allocated_robotdata(actorData); 
        
    for (int i = 0; i < n; i++){
      protocol::Coord *obstCoord = worldData->add_obstaclecoords();
      const double *obstTranslation = translations[i]->getSFVec3f();
      obstCoord->set_x(obstTranslation[0]);
      obstCoord->set_y(obstTranslation[2] * (-1));
      
      /*if (obstTranslation[0] < - length + 0.1 || obstTranslation[0] > length - 0.1 ||
          obstTranslation[2] < - width + 0.1 || obstTranslation[2] > width - 0.1)
      { 
        const double *rot = rotations[i]->getSFRotation();
        double newRotation[4];
        newRotation[0] = 0.0;
        newRotation[1] = 1.0;
        newRotation[2] = 0.0;
        newRotation[3] = rot[3] + M_PI / 2;
    
        rotations[i]->setSFRotation(newRotation);
      }*/
    }
    
    protocol::Coord *ballCoord = new protocol::Coord();
    const double *ballTranslation = ballTrans->getSFVec3f();
    ballCoord->set_x(ballTranslation[0]);
    ballCoord->set_y(ballTranslation[2] * (-1));
    worldData->set_allocated_ballcoord(ballCoord);
   
    client->sendWorldData(worldData);    
    protocol::WheelsVelocity newVelocity = client->getNewVelocity();
    
    leftMotor->setVelocity(newVelocity.leftwheelvelocity() * 50.0);
    rightMotor->setVelocity(newVelocity.rightwheelvelocity() * 50.0);
    
  };

  delete supervisor;
  return 0;
}
