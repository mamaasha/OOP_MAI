#include "/mnt/c/Users/User/OOP_MAI/include/Bear.h"

#include <iostream>

Bear::Bear(int health, int x, int y)
    : NPC("Bear", health, x, y) {}

void Bear::attack(NPC* target) {
    if (target->getName() == "Werewolf") {
        target->setHealth(0);
        notifyObservers("Bear killed Werewolf");
    }
}