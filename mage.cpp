#include "mage.h"
#include <iostream>

Mage::Mage(const std::string& name)
    : Player(name, 80), mana(100) {}

Mage::~Mage() {}

void Mage::displayStatus() const {
    std::cout << "mage " << name << " - health: " << health << ", mana: " << mana << ", score: " << score << std::endl;
}

void Mage::specialAbility() {
    if (health > 50) {
        std::cout << name << " se teleportira!" << std::endl;
    } else {
        std::cout << name << " je preslab za teleport!" << std::endl;
    }
}

void Mage::attackEnemy(Enemy* target) {
    if (target && target->isAlive()) {
        if (mana >= 20) {
            std::cout << name << " baca vatrenu kuglu!" << std::endl;
            target->takeDamage(40);
            mana -= 20;
        } else {
            std::cout << name << " koristi stap!" << std::endl;
            target->takeDamage(20);
        }
        if (!target->isAlive()) {
            addScore(10);
        }
    }
}

int Mage::getMana() const {
    return mana;
}
