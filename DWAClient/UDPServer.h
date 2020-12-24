//
// Created by yarkoe on 11.10.2020.
//

#ifndef DWACLIENT_UDPSERVER_H
#define DWACLIENT_UDPSERVER_H

#include <string>
#include <netinet/in.h>

typedef int SOCKET;

class UDPServer {
public:
    UDPServer(const std::string group, unsigned short port);
    int ReceiveMessage(char* buffer);
private:
    static void ExitIfTrue(bool expr, const std::string& exitMessage);

    SOCKET serverSocket;
    unsigned short serverPort;
    std::string group;
};

#endif //DWACLIENT_UDPSERVER_H
