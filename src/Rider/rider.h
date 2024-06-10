#ifndef RIDER_H
#define RIDER_H

#include "../Person/person.h"
#include "../Ride/ride.h"
#include <vector>

class Rider : public Person {
private:
    int id;
    vector<Ride> completedRides;
    Ride currentRide;
public:
    Rider(int id, string name);
    void createRide(int id, int origin, int dest, int seats);
    void updateRide(int id, int origin, int dest, int seats);
    void withdrawRide(int id);
    int closeRide();
    int getId() const;
};

#endif
