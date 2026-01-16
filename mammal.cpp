#include "mammal.h"
#include <iostream>

Mammal::Mammal(const std::string& name, int age, double weight, bool hasFur)
    : Animal(name, age, weight), hasFur(hasFur) {
    if (hasFur) {
        std::cout << "stvoren sisavac s dlakom" << std::endl;
    } else {
        std::cout << "stvoren sisavac s malo dlake" << std::endl;
    }
}

Mammal::~Mammal() {}
