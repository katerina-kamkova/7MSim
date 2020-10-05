#include <iostream>
#include "ObstacleAvoidance.h"
#include "SafeQueue.h"

using namespace std;

SafeQueue<WorldData> safeWorldDataQueue;

void sendData(WheelsVelocity velocity);
WorldData waitWorldData();


void sendData(WheelsVelocity velocity) {

}

int main() {

    while (true) {
        WorldData worldData = safeWorldDataQueue.dequeue();

        WheelsVelocity velocityData = ObstacleAvoidance::dwa(worldData);

        sendData(velocityData);
    }
}
