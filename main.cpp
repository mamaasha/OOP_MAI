#include <iostream>
#include "NPCFactory.h"
#include "NPC.h"
#include "Battle.h"
#include "LogObserver.h"
#include "PrintObserver.h"
#include "BattleVisitor.h"

int main() {

    NPCFactory factory;

    NPC* bear = factory.createNPC("Bear", 100, 0, 0);
    NPC* werewolf = factory.createNPC("Werewolf", 100, 100, 100);
    NPC* thief = factory.createNPC("Thief", 100, 200, 200);
 
    LogObserver logObserver;
    PrintObserver printObserver;

    bear->registerObserver(&logObserver);
    bear->registerObserver(&printObserver);
    werewolf->registerObserver(&logObserver);
    werewolf->registerObserver(&printObserver);
    thief->registerObserver(&logObserver);
    thief->registerObserver(&printObserver);

    Battle battle;

    battle.addNPC(bear);
    battle.addNPC(werewolf);
    battle.addNPC(thief);

    std::cout << "NPCs before battle:" << std::endl;
    battle.printNPCs();


    BattleVisitor battleVisitor;
    battle.startBattle(&battleVisitor);


    std::cout << "NPCs after battle:" << std::endl;
    battle.printNPCs();

    delete bear;
    delete werewolf;
    delete thief;

    return 0;
}

