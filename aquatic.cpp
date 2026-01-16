#include "aquatic.h"
#include <iostream>

Aquatic::Aquatic(const std::string& name, int age, double weight, double maxDiveDepth)
    : Animal(name, age, weight), maxDiveDepth(maxDiveDepth) {
    std::cout << "stvorena vodena zivotinja koja roni do " << maxDiveDepth << "m" << std::endl;
}

Aquatic::~Aquatic() {}
