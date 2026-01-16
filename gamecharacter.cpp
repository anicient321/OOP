#include "GameCharacter.h"
#include <iostream>

GameCharacter::GameCharacter(const std::string& name, int health)
    : name(name), health(health) {}

GameCharacter::~GameCharacter() {}

void GameCharacter::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

bool GameCharacter::isAlive() const {
    return health > 0;
}

int GameCharacter::getHealth() const {
    return health;
}

std::string GameCharacter::getName() const {
    return name;
}
