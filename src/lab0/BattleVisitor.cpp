#include <iostream>
#include "/mnt/c/Users/User/OOP_MAI/include/BattleVisitor.h"
#include "/mnt/c/Users/User/OOP_MAI/include/NPC.h"

void BattleVisitor::visit(NPC* npc) {
        std::cout << "Battle: " << npc->getName() << " is attacking!" << std::endl;
}