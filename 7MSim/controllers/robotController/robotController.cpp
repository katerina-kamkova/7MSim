#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h> 

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep();
  
  Motor *leftMotor = robot->getMotor("leftMotor");
  Motor *rightMotor = robot->getMotor("rightMotor");
 
  leftMotor->setPosition(INFINITY);
  rightMotor->setPosition(INFINITY);
 
  leftMotor->setVelocity(0);
  rightMotor->setVelocity(0);
  
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in server_address{};
  if (sock == -1)
  {
    std::cout << "Failed to create socket. Errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(7777);

  if(inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
  {
    std::cout << "Invalid address/ Address not supported" << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
  {
    std::cout << "Connection Failed " << errno << std::endl;
    exit(EXIT_FAILURE);
  }
  
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    std::string engines;
    recv(sock, &engines, sizeof(std::string), 0);
    if (engines == "engines")
    {
      int leftMotorVelocity = 0;
      recv(sock, &leftMotorVelocity, sizeof(int), 0);
      if (leftMotorVelocity >= -100 && leftMotorVelocity <= 100)
      {
        leftMotor->setVelocity(leftMotorVelocity/10);
      }
    
      int rightMotorVelocity = 0;
      recv(sock, &rightMotorVelocity, sizeof(int), 0);
      if (rightMotorVelocity >= -100 || rightMotorVelocity <= 100)
      {
        rightMotor->setVelocity(rightMotorVelocity/10);
      }
    }
  };

  close(sock);

  delete rightMotor;
  delete leftMotor;
  delete robot;
  
  return 0;
}
