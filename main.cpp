#include "Warrior.h"
#include "Mage.h"
#include "Gnome.h"
#include "Boss.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<GameCharacter*> characters;
    
    Warrior* conan = new Warrior("Conan");
    Mage* merlin = new Mage("Merlin");
    Gnome* gnomeo = new Gnome("Patnik");
    Gnome* sneaky = new Gnome("Ratnik");
    Boss* dragon = new Boss("ANTESEF");
    
    characters.push_back(conan);
    characters.push_back(merlin);
    characters.push_back(patnik);
    characters.push_back(ratnik);
    characters.push_back(antesef);
    
    for (size_t i = 0; i < characters.size(); ++i) {//pocetno stanje
        characters[i]->displayStatus();
    }
    
    
    std::cout << "\n1. conan napada patnika" << std::endl;
    conan->attackEnemy(patnik);
    conan->displayStatus();
    gnomeo->displayStatus();
    
    std::cout << "\n2. merlin napada Ratnika" << std::endl;
    merlin->attackEnemy(ratnik);
    merlin->displayStatus();
    sneaky->displayStatus();
    
    std::cout << "\n3. patnik napada conana" << std::endl;
    gnomeo->attackPlayer(conan);
    gnomeo->displayStatus();
    conan->displayStatus();
    
    std::cout << "\n4. merlin napada pantika" << std::endl;
    merlin->attackEnemy(patnik);
    merlin->displayStatus();
    gnomeo->displayStatus();
    
    std::cout << "\n5. antesef napada merlina" << std::endl;
    dragon->attackPlayer(merlin);
    dragon->displayStatus();
    merlin->displayStatus();
    
    std::cout << "\n6. merlin napada patnika" << std::endl;
    if (merlin->isAlive()) {
        merlin->attackEnemy(patnik);
        merlin->displayStatus();
        gnomeo->displayStatus();
    }
    
    std::cout << "\n7. conan napada antesefa" << std::endl;
    conan->attackEnemy(antesef);
    conan->displayStatus();
    dragon->displayStatus();
    
    std::cout << "\n8. merlin napada antesefa" << std::endl;
    if (merlin->isAlive()) {
        merlin->attackEnemy(antesef);
        merlin->displayStatus();
        dragon->displayStatus();
    }
    
    std::cout << "\n=== specijalne sposobnosti ===" << std::endl;
    for (size_t i = 0; i < characters.size(); ++i) {
        if (characters[i]->isAlive()) {
            characters[i]->specialAbility();
        }
    }
    
    std::cout << "\n=== prezivjeli likovi ===" << std::endl;
    GameCharacter* strongest = nullptr;
    for (size_t i = 0; i < characters.size(); ++i) {
        if (characters[i]->isAlive()) {
            characters[i]->displayStatus();
            if (!strongest || characters[i]->getHealth() > strongest->getHealth()) {
                strongest = characters[i];
            }
        }
    }
    
    if (strongest) {
        std::cout << "\nlik s najvise zdravlja: " << strongest->getName() << " (" << strongest->getHealth() << " hp)" << std::endl;
    }
    
    for (size_t i = 0; i < characters.size(); ++i) {
        delete characters[i];
    }
    
    return 0;
}
