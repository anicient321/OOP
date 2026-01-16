#include "zookeeper.h"
#include <iostream>

int ZooKeeper::totalAnimalsServed = 0;

void ZooKeeper::processAnimal(Animal* animal) {
    if (animal) {
        std::cout << "species: " << animal->getSpecies() 
                  << ", name: " << animal->getName() 
                  << ", food: " << animal->getDailyFood() << "kg" << std::endl;
        totalAnimalsServed++;
    }
}

int ZooKeeper::getTotalAnimalsServed() {
    return totalAnimalsServed;
}
