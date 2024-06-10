#include "../headers/system.h"
#include <iostream>

System::System(int drivers, vector<Rider>& riders) : drivers(drivers), riders(riders) {
    if (drivers < 2 || riders.size() < 2) {
        cout << "Not enough drivers or riders\n";
    }
}

void System::createRide(int riderId, int rideId, int origin, int dest, int seats) {
    if (drivers == 0) {
        cout << "No drivers around. Can't create ride\n";
        return;
    }

    for (Rider& rider : riders) {
        if (rider.getId() == riderId) {
            rider.createRide(rideId, origin, dest, seats);
            drivers--;
            break;
        }
    }
}

void System::updateRide(int riderId, int rideId, int origin, int dest, int seats) {
    for (Rider& rider : riders) {
        if (rider.getId() == riderId) {
            rider.updateRide(rideId, origin, dest, seats);
            break;
        }
    }
}

void System::withdrawRide(int riderId, int rideId) {
    for (Rider& rider : riders) {
        if (rider.getId() == riderId) {
            rider.withdrawRide(rideId);
            drivers++;
            break;
        }
    }
}

int System::closeRide(int riderId) {
    for (Rider& rider : riders) {
        if (rider.getId() == riderId) {
            drivers++;
            return rider.closeRide();
        }
    }
    return 0;
}
