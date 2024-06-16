#include "ride.h"

Ride::Ride() {
    id = origin = dest = seats = 0;
    rideStatus = RideStatus :: IDLE;
}

int Ride::calculateFare(bool isPriorityRider) {
    int dist = dest - origin;
    if(seats < 2)
        return dist * AMT_PER_KM * (isPriorityRider ? 0.75 : 1);
    return dist * seats * AMT_PER_KM * (isPriorityRider ? 0.5 : 0.75);
}

void Ride::setDest(int dest) {
    this -> dest = dest;
}

int Ride::getId() const {
    return id;
}

void Ride::setId(int id) {
    this -> id = id;
}

void Ride::setOrigin(int origin) {
    this -> origin = origin;
}

RideStatus Ride::getRideStatus() const {
    return rideStatus;
}

void Ride::setRideStatus(RideStatus rideStatus) {
    this -> rideStatus = rideStatus;
}

void Ride::setSeats(int seats) {
    this -> seats = seats;
}