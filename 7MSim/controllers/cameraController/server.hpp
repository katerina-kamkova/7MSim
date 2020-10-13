using namespace webots;

class Server{
  Server (bool tcp, int port) {
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

    if (listen(sock, 1) < 0) {
      std::cout << "Failed to listen on socket. Errno: " << errno << std::endl;
      exit(EXIT_FAILURE);
    }

    sockaddr_in client_address{};
    auto address_length = sizeof(client_address);
    connection = accept(sock, (struct sockaddr*)&client_address, (socklen_t*)&address_length);
    
    if (connection < 0) {
      std::cout << "Failed to grab connection. Errno: " << errno << std::endl;
      exit(EXIT_FAILURE);
    }
  }

  int sock;
  int connection; 
};
