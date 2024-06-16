#include <iostream>
#include "Driver/driver.h"
#include "Rider/rider.h"
#include "Driver/driver.h"
#include "System/system.h"

using namespace std;

// Utility function to check if two values are equal
template<typename T>
bool assertEqual(T expected, T actual, const string& testName) {
    if (expected == actual) {
        cout << testName << " passed." << endl;
        return true;
    } else {
        cout << testName << " failed. Expected: " << expected << ", Actual: " << actual << endl;
        return false;
    }
}

//Test function for creating a ride
void testCreateRide() {
    Rider rider(1, "Lucifer");
    rider.createRide(1, 50, 60, 1);
    int fare = rider.closeRide();
    assertEqual(200, fare, "testCreateRide"); // 10 km * 20 per km * 1 seat
}

// Test case for updating a ride
void testUpdateRide() {
    Rider rider(1, "Lucifer");
    rider.createRide(1, 50, 60, 1);
    rider.updateRide(1, 50, 60, 2);
    int fare = rider.closeRide();
    assertEqual(300, fare, "testUpdateRide");
}

// Test case for withdrawing a ride
void testWithdrawRide() {
    Rider rider(1, "Lucifer");
    int fare = rider.closeRide();
    rider.createRide(1, 50, 60, 1);
    rider.withdrawRide(1);
    fare = rider.closeRide();
    assertEqual(0, fare, "testWithdrawRide"); // Withdrawn ride should not generate fare
}

// Test case for system handling multiple riders
void testSystem() {
    Rider rider1(1, "Lucifer");
    Rider rider2(2, "Chloe");
    vector<Rider> riders = {rider1, rider2};
    System system(2, riders);

    system.createRide(1, 1, 50, 60, 1);
    system.updateRide(1, 1, 50, 60, 2);
    int fare = system.closeRide(1);
    assertEqual(300, fare, "testSystem");
}

int main() {
    testCreateRide();
    testUpdateRide();
    testWithdrawRide();
    testSystem();

    return 0;
}



