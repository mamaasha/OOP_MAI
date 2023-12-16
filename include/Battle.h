#pragma once
#include <vector>
#include "NPC.h"
#include "Visitor.h"

class Battle {

public:
    void addNPC(NPC* npc);
    void startBattle();
    void printNPCs() const;
    void startBattle(Visitor* visitor);

private:
    std::vector<NPC*> npcs;
    const int battleDistance = 10;
};
