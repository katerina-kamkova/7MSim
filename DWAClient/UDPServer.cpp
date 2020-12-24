//
// Created by yarkoe on 11.10.2020.
//

#include <sys/socket.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>

#include "UDPServer.h"

struct sockaddr_in udpServerAddr, clientAddr;
struct ip_mreq mreq;

UDPServer::UDPServer(const std::string group, unsigned const short port) {
    this->group = group;
    serverPort = port;

    ExitIfTrue((serverSocket = socket(AF_INET, SOCK_DGRAM, 0)) < 0, "Socket failed");

    u_int yes = 1;
    ExitIfTrue(setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char* ) &yes, sizeof(yes)) < 0, "Reusing ADDR failed");

    memset(&udpServerAddr, 0, sizeof(udpServerAddr));
    udpServerAddr.sin_family = AF_INET;
    udpServerAddr.sin_addr.s_addr = inet_addr(this->group.c_str());
    udpServerAddr.sin_port = htons(port);
    ExitIfTrue(bind(serverSocket, (const struct sockaddr*) &udpServerAddr, sizeof(udpServerAddr)) < 0, "bind failed");

    mreq.imr_multiaddr.s_addr = inet_addr(this->group.c_str());
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    ExitIfTrue(setsockopt(serverSocket, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*) &mreq, sizeof(mreq)) < 0, "setsockopt error");
}

void UDPServer::ExitIfTrue(bool expr, const std::string& exitMessage) {
    if (expr)
    {
        perror(exitMessage.c_str());
        exit(EXIT_FAILURE);
    }
}

int UDPServer::ReceiveMessage(char *buffer) {
    socklen_t len = sizeof(clientAddr);

    int n = recvfrom(serverSocket, (char *)buffer, 4096, 0, (struct sockaddr *)&clientAddr, &len);

    if (n < 0) {
        return false;
    }

    buffer[n] = '\0';

    return n;
}
