#include "lion.h"
#include <stdexcept>

Lion::Lion(const std::string& name, int age, double weight)
    : Animal(name, age, weight), Mammal(name, age, weight, true) {}

Lion::~Lion() {}

std::string Lion::getSpecies() const {
    return "lav";
}

double Lion::getDailyFood() const {
    double food = weight * 0.06;
    if (food == 0) {
        throw std::logic_error("kolicina hrane ne moze biti 0");
    }
    return food;
}
