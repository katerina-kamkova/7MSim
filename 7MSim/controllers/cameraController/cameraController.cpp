// File:          cameraController.cpp
// Date:          08.04.2020
// Description:   shows the field in the window
// Author:        katerina kamkova

#include <webots/Robot.hpp>
#include <webots/Camera.hpp>

// For socket functions
#include <sys/socket.h> 
// For sockaddr_in
#include <netinet/in.h>
// For exit() and EXIT_FAILURE 
#include <cstdlib> 
// For cout
#include <iostream> 
// For read
#include <unistd.h> 

using namespace webots;

int main(int argc, char **argv) { 
  // create the Robot instance.
  Robot *robot = new Robot();
  // get the time step of the current world.
  int timeStep = (int)robot->getBasicTimeStep();
  
  // Create a camera instance
  Camera *camera = robot->getCamera("camera");
  camera->enable(1);  
  
  /*
  // Create a socket (IPv4, TCP)
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    std::cout << "Failed to create socket. errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  // Listen to port 7777 on any address
  sockaddr_in sockaddr;
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_addr.s_addr = INADDR_ANY;
  sockaddr.sin_port = htons(7777); // htons is necessary to convert a number to
                                   // network byte order
  if (bind(sockfd, (struct sockaddr*)&sockaddr, sizeof(sockaddr)) < 0) {
    std::cout << "Failed to bind to port 7777. errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  // Start listening. Hold just 1 connection in the queue
  if (listen(sockfd, 1) < 0) {
    std::cout << "Failed to listen on socket. errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  // Grab a connection from the queue
  auto addrlen = sizeof(sockaddr);
  int connection = accept(sockfd, (struct sockaddr*)&sockaddr, (socklen_t*)&addrlen);
  if (connection < 0) {
    std::cout << "Failed to grab connection. errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  unsigned long long int pictureSize = camera->getWidth() * camera->getHeight() * 4;
  bool t = true;*/
  
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    /*if (t) {
      send(connection, &pictureSize, sizeof(unsigned long long int), 0);
      
      const unsigned char* picture = camera->getImage(); 
      
      send(connection, picture, pictureSize, 0);
      }
      t = false;*/
      /*send(connection, &pictureSize, sizeof(unsigned long long int), 0);
      unsigned char array[pictureSize];
      for (int i = 0; i < pictureSize / 96; i++)
      {
        array[i] = 102;
      }
      for (int i = 0; i < 96; i ++)
      {
        send(connection, &array, pictureSize / 96, 0);
      }*/
    //std::string response = std::to_string(pictureSize) + "\n";
    // send(connection, rawPicture, pictureSize, 0);
  };

  // Close the connections
  //close(connection);
  //close(sockfd);

  delete camera;
  delete robot;
  return 0;
}
