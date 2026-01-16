#ifndef MAGE_H
#define MAGE_H

#include "Player.h"
#include "Enemy.h"

class Mage : public Player {
private:
    int mana;

public:
    Mage(const std::string& name);
    ~Mage();
    
    void displayStatus() const override;
    void specialAbility() override;
    void attackEnemy(Enemy* target) override;
    int getMana() const;
};

#endif
