//
// Created by yarkoe on 11.10.2020.
//

#include <sys/socket.h>
#include <unistd.h>

#include "TCPServer.h"

struct sockaddr_in serverAddr;

TCPServer::TCPServer(unsigned short port) {
    serverPort = port;

    ExitIfTrue((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == 0, "Socket failed");

    int opt = 1;
    ExitIfTrue(setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)), "Setsocopt failed");

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    ExitIfTrue(bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0, "Binding failed");
}

void TCPServer::StartListening() {
    ExitIfTrue(listen(serverSocket, 3) < 0, "Listening failed");
}

Client TCPServer::AcceptNewClient() {
    SOCKET clientSocket;

    int serverAddressLen = sizeof(serverAddr);
    ExitIfTrue((clientSocket = accept(serverSocket, (struct sockaddr *)&serverAddr, (socklen_t*)&serverAddressLen)) < 0, "Accept failed");

    return Client{
            .clientType = supervisor,
            .clientSocket = clientSocket
    };
}

void TCPServer::ExitIfTrue(bool expr, const std::string& exitMessage) {
    if (expr)
    {
        perror(exitMessage.c_str());
        exit(EXIT_FAILURE);
    }
}

void TCPServer::SendToClient(Client client, char *message, int messageSize) {
    send(client.clientSocket, message, messageSize, 0);
}

int TCPServer::ReceiveFromClient(Client client, char *buffer) {
    return read(client.clientSocket, buffer, 1024);
}
