#include "/mnt/c/Users/User/OOP_MAI/include/Thief.h"

#include <iostream>

Thief::Thief(int health, int x, int y)
    : NPC("Thief", health, x, y) {}

void Thief::attack(NPC* target) {
    if (target->getName() == "Bear") {
        target->setHealth(0);
        notifyObservers("Thief killed Bear");
    }
}