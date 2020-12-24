#include "messages_robocup_ssl_wrapper.pb.h"
#include "UDPServer.h"
#include "TCPServer.h"
#include "world_data.pb.h"
#include "ObstacleAvoidance.h"

using namespace std;
using namespace protobuf_messages_5frobocup_5fssl_5fwrapper_2eproto;

const int UDP_PORT = 10005;
const string GROUP_ADDRESS = "224.5.23.2";
const int TCP_PORT = 4343;

SSL_WrapperPacket ReceiveSSLWrapperPacket(UDPServer &udpServer);
void SendWheelsVelocityToClient(const Client& client, const protocol::WheelsVelocity& velocity);
protocol::WorldData CreateWorldData(SSL_WrapperPacket packet, protocol::WheelsVelocity wheelsVelocity);

SSL_WrapperPacket ReceiveSSLWrapperPacket(UDPServer &udpServer) {
    char sslWrapperPacketBuffer[4096] = {0};

    int size = 0;

    while (size < 5) {
        size = udpServer.ReceiveMessage(sslWrapperPacketBuffer);
    }

    SSL_WrapperPacket sslWrapperPacket;

    if (!sslWrapperPacket.ParseFromArray(sslWrapperPacketBuffer, size)) {
        perror("Failed to parse ssl wrapper packet from array");
        exit(EXIT_FAILURE);
    }

    return sslWrapperPacket;
}

void SendWheelsVelocityToClient(const Client& client, const protocol::WheelsVelocity& velocity) {
    int size = velocity.ByteSize();
    char* velocityArray = new char[size];
    velocity.SerializeToArray(velocityArray, size);

    TCPServer::SendToClient(client, velocityArray, size);
}

protocol::WorldData CreateWorldData(SSL_WrapperPacket packet, protocol::WheelsVelocity wheelsVelocity) {
    protocol::WorldData worldData;

    auto *ballCoord = new protocol::Coord();
    ballCoord->set_x(packet.detection().balls(0).x());
    ballCoord->set_y(packet.detection().balls(0).y());
    worldData.set_allocated_ballcoord(ballCoord);

    auto *robotCoord = new protocol::Coord();
    robotCoord->set_x(packet.detection().robots_blue(0).x());
    robotCoord->set_y(packet.detection().robots_blue(0).y());

    auto *robotPosition = new protocol::Position();
    robotPosition->set_allocated_coord(robotCoord);
    robotPosition->set_theta(packet.detection().robots_blue(0).orientation());

    auto *robotData = new protocol::RobotData();
    robotData->set_allocated_position(robotPosition);
    robotData->set_allocated_wheelsvelocity(wheelsVelocity.New());
    worldData.set_allocated_robotdata(robotData);

    for (const auto& robot : packet.detection().robots_yellow()) {
        protocol::Coord *obstacleCoord = worldData.add_obstaclecoords();
        obstacleCoord->set_x(robot.x());
        obstacleCoord->set_y(robot.y());
    }

    return worldData;
}

int main() {
    UDPServer udpServer(GROUP_ADDRESS, UDP_PORT);

    TCPServer tcpServer(TCP_PORT);
    tcpServer.StartListening();
    Client supervisorClient = tcpServer.AcceptNewClient();

    protocol::WheelsVelocity velocityData;
    velocityData.set_leftwheelvelocity(0.);
    velocityData.set_rightwheelvelocity(0.);

    while (true) {
        cout << "Before receiving sll wrapper packet" << std::endl;
        SSL_WrapperPacket sslWrapperPacket = ReceiveSSLWrapperPacket(udpServer);
        sslWrapperPacket.PrintDebugString();
        if (!sslWrapperPacket.has_detection()) {
            cout << "Continue..." << std::endl;
            continue;
        }

        cout << "Before creating world data" << std::endl;
        protocol::WorldData worldData;
        worldData.CopyFrom(CreateWorldData(sslWrapperPacket, velocityData));
        cout << "world data created" << std::endl;
        worldData.PrintDebugString();

        cout << "Before creating velocity data" << std::endl;
        velocityData.CopyFrom(ObstacleAvoidance::dwa(worldData));
        cout << "velocity data created" << std::endl;
        velocityData.PrintDebugString();

        cout << "Before sending velocity" << std::endl;
        SendWheelsVelocityToClient(supervisorClient, velocityData);
        cout << "velocity sended to client" << std::endl;
    }
}
