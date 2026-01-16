#include "warrior.h"
#include <iostream>

Warrior::Warrior(const std::string& name)
    : Player(name, 120), shieldActive(false) {}

Warrior::~Warrior() {}

void Warrior::displayStatus() const {
    std::cout << "warrior " << name << " - health: " << health << ", score: " << score << std::endl;
}

void Warrior::specialAbility() {
    std::cout << name << " aktivira stit!" << std::endl;
    shieldActive = true;
}

void Warrior::attackEnemy(Enemy* target) {
    if (target && target->isAlive()) {
        std::cout << name << " napada macem!" << std::endl;
        target->takeDamage(20);
        if (!target->isAlive()) {
            addScore(10);
        }
    }
}

void Warrior::takeDamage(int damage) {
    if (shieldActive) {
        damage = damage / 2;
        shieldActive = false;
        std::cout << name << " blokira stit! steta smanjena na " << damage << std::endl;
    }
    GameCharacter::takeDamage(damage);
}
