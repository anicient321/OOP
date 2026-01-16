#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>

class GameCharacter {
protected:
    int health;
    std::string name;

public:
    GameCharacter(const std::string& name, int health);
    virtual ~GameCharacter();
    
    virtual void displayStatus() const = 0;
    virtual void specialAbility() = 0;
    
    void takeDamage(int damage);
    bool isAlive() const;
    int getHealth() const;
    std::string getName() const;
};

#endif
