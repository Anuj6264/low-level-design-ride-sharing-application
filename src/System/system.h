#ifndef SYSTEM_H
#define SYSTEM_H

#include "../Rider/rider.h"
#include <vector>

class System {
private:
    int drivers;
    vector<Rider> riders;
public:
    System(int drivers, vector<Rider>& riders);
    void createRide(int riderId, int rideId, int origin, int dest, int seats);
    void updateRide(int riderId, int rideId, int origin, int dest, int seats);
    void withdrawRide(int riderId, int rideId);
    int closeRide(int riderId);
};

#endif
