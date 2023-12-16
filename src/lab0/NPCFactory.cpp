#include "/mnt/c/Users/User/OOP_MAI/include/NPCFactory.h"
#include "/mnt/c/Users/User/OOP_MAI/include/Bear.h"
#include "/mnt/c/Users/User/OOP_MAI/include/Werewolf.h"
#include "/mnt/c/Users/User/OOP_MAI/include/Thief.h"

NPC* NPCFactory::createNPC(const std::string& type, int health, int x, int y) {
    if (type == "Bear") {
        return new Bear(health, x, y);
    }
    else if (type == "Werewolf") {
        return new Werewolf(health, x, y);
    }
    else if (type == "Thief") {
        return new Thief(health, x, y);
    }
    else {
        return nullptr;
    }
}

