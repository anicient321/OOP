#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
    std::string name;
    int age;
    double weight;
    
    Animal(const std::string& name, int age, double weight);

public:
    virtual ~Animal();
    
    virtual std::string getSpecies() const = 0;
    virtual double getDailyFood() const = 0;
    virtual std::string getName() const;
};

#endif
