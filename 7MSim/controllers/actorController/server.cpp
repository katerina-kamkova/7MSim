#include <sys/socket.h>
#include <arpa/inet.h>
#include <iostream>
#include <map>
#include "server.h"

// Start tcp or udp server
// tcp = do you want tcp server ? true : false
Server::Server (bool tcp, int port) {
  sock = tcp ? socket(AF_INET, SOCK_STREAM, 0) : socket(AF_INET, SOCK_DGRAM, 0);
  if (sock == -1) {
    std::cout << "Failed to create socket. Errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }

  sockaddr_in socket_address{};
  socket_address.sin_family = AF_INET;
  socket_address.sin_addr.s_addr = INADDR_ANY;
  socket_address.sin_port = htons(port);

  if (bind(sock, (struct sockaddr*)&socket_address, sizeof(sockaddr)) < 0) {
    std::cout << "Failed to bind to port " << port << ". Errno: " << errno << std::endl;
    exit(EXIT_FAILURE);
  }
}

RobotStruct Server::connectClient() const {
  if (listen(sock, 32) < 0) {
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

  int robotNumber = 0;
  recv(connection, &robotNumber, sizeof(int), 0);

  RobotStruct robot{};
  robot.number = robotNumber;
  robot.connection = connection;
  return robot;
}

protocol::WheelsVelocity Server::getVelocity(int connection) {
  protocol::WheelsVelocity velocity;
  recv(connection, &velocity, sizeof(protocol::WheelsVelocity), 0);
  return velocity;
}
