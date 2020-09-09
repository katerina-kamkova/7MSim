#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <arpa/inet.h>
#include <cstring>
#include "client.h"
#include "robot.h"

using namespace webots;

Client::Client(bool tcp, int port)
{
  sock = tcp ? socket(AF_INET, SOCK_STREAM, 0) : socket(AF_INET, SOCK_DGRAM, 0);
  sockaddr_in server_address{};
  if (sock == -1)
  {
    std::cout << "Failed to create socket. Errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);

  // 127.0.0.1
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
}

void Client::sendNumber(int number) const{
    send(sock, &number, sizeof(int), 0);
}

void Client::sendData(int number, Field* transField, Field* rotField){
  const double *translation = transField->getSFVec3f();
  const double *rotation = rotField->getSFRotation();

  send(sock, &number, sizeof(int), 0);
  std::cout << number << std::endl;
  send(sock, translation[0], sizeof(double), 0);
  std::cout << translation[0] << std::endl;
  send(sock, translation[1], sizeof(double), 0);
  std::cout << translation[1] << std::endl;
  send(sock, rotation[3], sizeof(double), 0);
  std::cout << rotation[3] << std::endl;  
}
