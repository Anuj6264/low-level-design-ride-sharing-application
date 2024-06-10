#include "rider.h"
#include <iostream>

Rider::Rider(int id, string name) : Person(name), id(id) {}

void Rider::createRide(int id, int origin, int dest, int seats) {
    if (origin >= dest) {
        cout << "Wrong values of Origin and Destination provided. Can't create ride\n";
        return;
    }

    currentRide.setId(id);
    currentRide.setOrigin(origin);
    currentRide.setDest(dest);
    currentRide.setSeats(seats);
    currentRide.setRideStatus(RideStatus::CREATED);
}

void Rider::updateRide(int id, int origin, int dest, int seats) {
    if (currentRide.getRideStatus() == RideStatus::WITHDRAWN) {
        cout << "Can't update ride. Ride was withdrawn\n";
        return;
    }
    if (currentRide.getRideStatus() == RideStatus::COMPLETED) {
        cout << "Can't update ride. Ride already complete\n";
        return;
    }

    createRide(id, origin, dest, seats);
}

void Rider::withdrawRide(int id) {
    if (currentRide.getId() != id) {
        cout << "Wrong ride Id as input. Can't withdraw current ride\n";
        return;
    }
    if (currentRide.getRideStatus() != RideStatus::CREATED) {
        cout << "Ride wasn't in progress. Can't withdraw ride\n";
        return;
    }

    currentRide.setRideStatus(RideStatus::WITHDRAWN);
}

int Rider::getId() const {
    return id;
}

int Rider::closeRide() {
    if (currentRide.getRideStatus() != RideStatus::CREATED) {
        cout << "Ride wasn't in progress. Can't close ride\n";
        return 0;
    }

    currentRide.setRideStatus(RideStatus::COMPLETED);
    completedRides.push_back(currentRide);
    return currentRide.calculateFare(completedRides.size() >= 10);
}
