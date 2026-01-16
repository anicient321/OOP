#include "Lion.h"
#include "Elephant.h"
#include "Dolphin.h"
#include "SeaTurtle.h"
#include "ZooSection.h"
#include "ZooKeeper.h"
#include <iostream>
#include <memory>

int main() {
    try {
        ZooSection<Animal> zoo;
        ZooKeeper keeper;
        auto lion = std::make_unique<Lion>("simba", 5, 190.0);
        auto elephant = std::make_unique<Elephant>("dumbo", 10, 5000.0);
        auto dolphin = std::make_unique<Dolphin>("flipper", 8, 200.0);
        auto turtle = std::make_unique<SeaTurtle>("crush", 50, 150.0);
        
        zoo.addAnimal(std::move(lion));
        zoo.addAnimal(std::move(elephant));
        zoo.addAnimal(std::move(dolphin));
        zoo.addAnimal(std::move(turtle));
        
        std::cout << "\n=== hranjenje zivotinja ===" << std::endl;
        for (size_t i = 0; i < zoo.size(); ++i) {
            keeper.processAnimal(zoo.getAnimal(i));
        }

        std::cout << "statistikaaa" << std::endl;
        std::cout << "ukupna dnevna hrana: " << zoo.totalFood() << "kg" << std::endl;
        std::cout << "broj nahranjenih zivotinja: " << ZooKeeper::getTotalAnimalsServed() << std::endl;
        
        std::cout << "\n=== testiranje iznimki ===" << std::endl;
        
        try {
            std::cout << "pokusaj stvaranja zivotinje s praznim imenom:" << std::endl;
            auto invalid1 = std::make_unique<Lion>("", 5, 190.0);
        } catch (const std::invalid_argument& e) {
            std::cout << "iznimka: " << e.what() << std::endl;
        }
        
        try {
            std::cout << "pokusaj stvaranja zivotinje s negativnim godinama:" << std::endl;
            auto invalid2 = std::make_unique<Lion>("leo", -1, 190.0);
        } catch (const std::invalid_argument& e) {
            std::cout << "iznimka: " << e.what() << std::endl;
        }
        
        try {
            std::cout << "pokusaj stvaranja zivotinje s tezinom 0: " << std::endl;
            auto invalid3 = std::make_unique<Lion>("leo", 5, 0);
        } catch (const std::invalid_argument& e) {
            std::cout << "iznimka: " << e.what() << std::endl;
        }
        
        try {
            std::cout << "pokusaj dodavanja nullptr:" << std::endl;
            zoo.addAnimal(nullptr);
        } catch (const std::runtime_error& e) {
            std::cout << "iznimka: " << e.what() << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cout << "greska: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
