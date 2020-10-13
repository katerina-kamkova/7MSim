//
// Created by yarkoe on 11.10.2020.
//

#ifndef DWACLIENT_TCPSERVER_H
#define DWACLIENT_TCPSERVER_H

#include <string>
#include <netinet/in.h>

typedef int SOCKET;

enum ClientType {supervisor, robot};

struct Client {
    ClientType clientType;
    int clientSocket;
};

class TCPServer {
public:
    TCPServer(unsigned short port);
    void StartListening();
    Client AcceptNewClient();
    static void SendToClient(Client client, char* message, int messageSize);
    static int ReceiveFromClient(Client client, char* buffer);
private:
    static void ExitIfTrue(bool expr, const std::string& exitMessage);

    SOCKET serverSocket;
    unsigned short serverPort;
};

#endif //DWACLIENT_TCPSERVER_H
