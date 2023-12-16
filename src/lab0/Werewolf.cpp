#include "/mnt/c/Users/User/OOP_MAI/include/Werewolf.h"

#include <iostream>

Werewolf::Werewolf(int health, int x, int y)
    : NPC("Werewolf", health, x, y) {}

void Werewolf::attack(NPC* target) {
    if (target->getName() == "Thief") {
        target->setHealth(0);
        notifyObservers("Werewolf killed Thief");
    }
}