#include "boss.h"
#include <iostream>

Boss::Boss(const std::string& name)
    : Enemy(name, 300, 8) {}

Boss::~Boss() {}

void Boss::displayStatus() const {
    std::cout << "boss " << name << " - health: " << health << ", difficulty: " << difficulty << std::endl;
}

void Boss::specialAbility() {
    if (health < MAX_HEALTH) {
        int heal = 50;
        if (health + heal > MAX_HEALTH) {
            heal = MAX_HEALTH - health;
        }
        health += heal;
        std::cout << name << " se regenerira! dobiva " << heal << " health" << std::endl;
    } else {
        std::cout << name << " ima maksimalno zdravlje!" << std::endl;
    }
}

void Boss::attackPlayer(Player* target) {
    if (target && target->isAlive()) {
        std::cout << name << " razbija zemlju!" << std::endl;
        int damage = 10 * difficulty;
        target->takeDamage(damage);
    }
}
