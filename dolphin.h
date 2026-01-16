#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "Mammal.h"
#include "Aquatic.h"

class Dolphin : public Mammal, public Aquatic {
public:
    Dolphin(const std::string& name, int age, double weight);
    ~Dolphin();
    
    std::string getSpecies() const override;
    double getDailyFood() const override;
};

#endif
