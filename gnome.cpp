#include "gnome.h"
#include <iostream>

Gnome::Gnome(const std::string& name)
    : Enemy(name, 90, 3) {}

Gnome::~Gnome() {}

void Gnome::displayStatus() const {
    std::cout << "gnome " << name << " - health: " << health << ", difficulty: " << difficulty << std::endl;
}

void Gnome::specialAbility() {
    if (health > 20) {
        std::cout << name << " svira trubu i zove gnomove u pomoc!" << std::endl;
    } else {
        std::cout << name << " je preslab za sviranje trube!" << std::endl;
    }
}

void Gnome::attackPlayer(Player* target) {
    if (target && target->isAlive()) {
        std::cout << name << " puca iz luka!" << std::endl;
        int damage = 5 * difficulty;
        target->takeDamage(damage);
    }
}
