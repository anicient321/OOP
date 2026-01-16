#ifndef LION_H
#define LION_H

#include "mammal.h"

class Lion : public Mammal {
public:
    Lion(const std::string& name, int age, double weight);
    ~Lion();
    
    std::string getSpecies() const override;
    double getDailyFood() const override;
};

#endif
