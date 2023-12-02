#include "/mnt/c/Users/User/OOP_MAI/include/Battle.h"
#include <iostream>
#include <algorithm>
#include <sstream>

void Battle::addNPC(NPC* npc) {
    npcs.push_back(npc);
}

void Battle::startBattle(Visitor* visitor) {
    for (size_t i = 0; i < npcs.size(); i++) {
        for (size_t j = i + 1; j < npcs.size(); j++) {
            if (std::abs(npcs[i]->getX() - npcs[j]->getX()) <= battleDistance &&
                std::abs(npcs[i]->getY() - npcs[j]->getY()) <= battleDistance) {
                npcs[i]->accept(visitor);
                npcs[j]->accept(visitor);
            }
        }
    }
    npcs.erase(std::remove_if(npcs.begin(), npcs.end(), [](NPC* npc) { return npc->getHealth() <= 0; }), npcs.end());
}

void Battle::printNPCs() const {
    for (const NPC* npc : npcs) {
        std::stringstream ss;
        ss << "NPC: " << npc->getName() << ", Health: " << npc->getHealth() << ", Position: (" << npc->getX() << ", " << npc->getY() << ")";
        std::cout << ss.str() << std::endl;
    }
}
void Battle::startBattle() {}