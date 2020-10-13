#include "ObstacleAvoidance.h"
#include "world_data.pb.h"
#include "TCPServer.h"

using namespace std;

const int port = 4343;

void sendWorldDataToClient(const Client& client, const protocol::WheelsVelocity& velocity);
protocol::WorldData ReceiveWorldDataFromClient(const Client& client);

void sendWorldDataToClient(const Client& client, const protocol::WheelsVelocity& velocity) {
    int size = velocity.ByteSize();
    char* velocityArray = new char[size];
    velocity.SerializeToArray(velocityArray, size);

    TCPServer::SendToClient(client, velocityArray, size);
}

protocol::WorldData ReceiveWorldDataFromClient(const Client& client)
{
    char worldDataArray[1024] = {0};
    int size = TCPServer::ReceiveFromClient(client, worldDataArray);

    protocol::WorldData newWorldData;

    if (!newWorldData.ParseFromArray(worldDataArray, size))
    {
        perror("Failed to parse worldData from array");
        exit(EXIT_FAILURE);
    }

    return newWorldData;
}

int main() {
    TCPServer tcpServer(port);
    tcpServer.StartListening();

    Client supervisorClient = tcpServer.AcceptNewClient();

    while (true) {
        protocol::WorldData worldData = ReceiveWorldDataFromClient(supervisorClient);

        protocol::WheelsVelocity velocityData;
        velocityData.CopyFrom(ObstacleAvoidance::dwa(worldData));

        sendWorldDataToClient(supervisorClient, velocityData);
    }
}
