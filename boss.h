#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
#include "Player.h"

class Boss : public Enemy {
private:
    static const int MAX_HEALTH = 300;

public:
    Boss(const std::string& name);
    ~Boss();
    
    void displayStatus() const override;
    void specialAbility() override;
    void attackPlayer(Player* target) override;
};

#endif
