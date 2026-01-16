#include "animal.h"
#include <stdexcept>

Animal::Animal(const std::string& name, int age, double weight)
    : name(name), age(age), weight(weight) {
    if (name.empty()) {
        throw std::invalid_argument("ime ne moze biti prazno");
    }
    if (age < 0) {
        throw std::invalid_argument("godine ne mogu biti negativne");
    }
    if (weight <= 0) {
        throw std::invalid_argument("tezina mora biti veca od 0");
    }
}

Animal::~Animal() {}

std::string Animal::getName() const {
    return name;
}
