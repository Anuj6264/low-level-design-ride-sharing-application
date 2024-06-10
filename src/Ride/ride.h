#ifndef RIDE_H
#define RIDE_H

enum RideStatus { IDLE, CREATED, WITHDRAWN, COMPLETED };

class Ride {
public:
    static const int AMT_PER_KM = 20;
    Ride();
    int calculateFare(bool isPriorityRider);
    void setDest(int dest);
    int getId() const;
    void setId(int id);
    void setOrigin(int origin);
    RideStatus getRideStatus() const;
    void setRideStatus(RideStatus rideStatus);
    void setSeats(int seats);

private:
    int id;
    int origin, dest;
    int seats;
    RideStatus rideStatus;
};

#endif