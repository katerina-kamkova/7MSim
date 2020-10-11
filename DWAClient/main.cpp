#include "ObstacleAvoidance.h"
#include "world_data.pb.h"
#include "SafeQueue.h"

using namespace std;

SafeQueue<protocol::WorldData> safeWorldDataQueue;

void sendData(const protocol::WheelsVelocity& velocity);

void sendData(const protocol::WheelsVelocity& velocity) {

}

int main() {

    protocol::WorldData worldData;
    worldData.CopyFrom(safeWorldDataQueue.dequeue());

    protocol::WheelsVelocity velocityData;
    velocityData.CopyFrom(ObstacleAvoidance::dwa(worldData));

    sendData(velocityData);
}
