#include <webots/Robot.hpp>
#include <webots/Camera.hpp>

#include <sys/socket.h> 
#include <netinet/in.h> 
#include <cstdlib> 
#include <unistd.h> 

using namespace webots;

int main(int argc, char **argv) { 
  Robot *robot = new Robot();
  int timeStep = (int)robot->getBasicTimeStep(); // get the time step of the current world
  
  Camera *camera = robot->getCamera("camera");
  camera->enable(1);    
  
  // start server
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    std::cout << "Failed to create socket. Errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  sockaddr_in socket_address{};
  socket_address.sin_family = AF_INET;
  socket_address.sin_addr.s_addr = INADDR_ANY;
  socket_address.sin_port = htons(7777);

  if (bind(sock, (struct sockaddr*)&socket_address, sizeof(sockaddr)) < 0) {
    std::cout << "Failed to bind to port 7777. Errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  if (listen(sock, 1) < 0) {
    std::cout << "Failed to listen on socket. Errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  sockaddr_in client_address{};
  auto address_length = sizeof(client_address);
  int connection = accept(sock, (struct sockaddr*)&client_address, (socklen_t*)&address_length);
    
  if (connection < 0) {
    std::cout << "Failed to grab connection. Errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }
  
  unsigned int width = camera->getWidth();
  unsigned int height = camera->getHeight();
  unsigned long long int pictureSize = width * height * 4;
  
  send(connection, &width, sizeof(unsigned int), 0);
  send(connection, &height, sizeof(unsigned int), 0);
  
  // Main loop:
  // - perform simulation steps until Webots is stopping the controller
  while (robot->step(timeStep) != -1) {
    const unsigned char* picture = camera->getImage();
    send(connection, picture, pictureSize, 0); 
  };
  
  close(connection);
  close(sock);

  delete camera;
  delete robot;
  
  return 0;
}
