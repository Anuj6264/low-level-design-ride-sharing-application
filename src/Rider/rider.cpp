#include "rider.h"
#include <iostream>

Rider::Rider(int id, string name) {
    this -> id = id;
    this -> name = name;
}

void Rider::createRide(int id, int origin, int dest, int seats) {
    if (origin >= dest) {
        cout << "Wrong values of Origin and Destination provided. Can't create ride\n";
        return;
    }
    Ride currentRide;
    currentRide.setId(id);
    currentRide.setOrigin(origin);
    currentRide.setDest(dest);
    currentRide.setSeats(seats);
    currentRide.setRideStatus(RideStatus::CREATED);
    allRides.push_back(currentRide);
}

void Rider::updateRide(int id, int origin, int dest, int seats) {
    //We are not checking for valid ID here as the problem description says to create a ride if there doesn't exists one.
    int currentRideIndex;
    bool rideAlreadyExists = false;
    for(currentRideIndex = 0; currentRideIndex < allRides.size(); currentRideIndex++) {
        if(allRides[currentRideIndex].getId() == id) {
            rideAlreadyExists = true;
            break;
        } 
    }
    if (allRides[currentRideIndex].getRideStatus() == RideStatus::WITHDRAWN) {
        cout << "Can't update ride. Ride was withdrawn\n";
        return;
    }
    if (allRides[currentRideIndex].getRideStatus() == RideStatus::COMPLETED) {
        cout << "Can't update ride. Ride already complete\n";
        return;
    }

    allRides[currentRideIndex].setId(id);
    allRides[currentRideIndex].setOrigin(origin);
    allRides[currentRideIndex].setDest(dest);
    allRides[currentRideIndex].setSeats(seats);
    if(!rideAlreadyExists) {
        allRides[currentRideIndex].setRideStatus(RideStatus::CREATED);
        allRides.push_back(allRides[currentRideIndex]);
    }
}

void Rider::withdrawRide(int id) {
    int currentRideIndex;
    bool rideAlreadyExists = false;
    for(currentRideIndex = 0; currentRideIndex < allRides.size(); currentRideIndex++) {
        if(allRides[currentRideIndex].getId() == id) {
            rideAlreadyExists = true;
            break;
        } 
    }
    if (!rideAlreadyExists) {
        cout << "Wrong ride Id as input. Can't withdraw current ride\n";
        return;
    }
    if (allRides[currentRideIndex].getRideStatus() != RideStatus::CREATED) {
        cout << "Ride wasn't in progress. Can't withdraw ride\n";
        return;
    }

    allRides[currentRideIndex].setRideStatus(RideStatus::WITHDRAWN);
}

int Rider::getId() const {
    return id;
}

//This function should always close the latest ride(last ride in all rides vector)
int Rider::closeRide() {
    if(!allRides.size()) {
        cout << "No ride found \n";
        return 0;
    }
    if (allRides.back().getRideStatus() != RideStatus::CREATED) {
        cout << "Ride wasn't in progress. Can't close ride\n";
        return 0;
    }

    allRides.back().setRideStatus(RideStatus::COMPLETED);
    completedRides.push_back(allRides.back());
    return allRides.back().calculateFare(completedRides.size() >= 10);
}
