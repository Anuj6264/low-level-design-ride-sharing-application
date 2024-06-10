#include "../headers/system.h"
#include "../headers/rider.h"
#include "../headers/driver.h"
#include <iostream>

int main() {
    Rider rider(1, "Lucifer");
    Driver driver("Amenadiel");
    Rider rider1(2, "Chloe");
    Rider rider2(3, "Maze");

    vector<Rider> riders = {rider, rider1, rider2};
    System system(3, riders);

    rider.createRide(1, 50, 60, 1);
    std::cout << rider.closeRide() << std::endl;
    rider.updateRide(1, 50, 60, 2);
    std::cout << rider.closeRide() << std::endl;

    std::cout << "*****************************************************************" << std::endl;

    system.createRide(1, 1, 50, 60, 1);
    system.withdrawRide(1, 1);
    system.updateRide(1, 1, 50, 60, 2);
    std::cout << system.closeRide(1) << std::endl;

    std::cout << "*****************************************************************" << std::endl;

    system.createRide(1, 1, 50, 60, 1);
    system.updateRide(1, 1, 50, 60, 2);
    std::cout << system.closeRide(1) << std::endl;

    return 0;
}


