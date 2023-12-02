#include <iostream>
#include "NPCFactory.h"
#include "NPC.h"
#include "Battle.h"
#include "LogObserver.h"
#include "PrintObserver.h"
#include "BattleVisitor.h"

int main() {
    // Создаем фабрику NPC
    NPCFactory factory;

    // Создаем объекты NPC
    NPC* bear = factory.createNPC("Bear", 100, 0, 0);
    NPC* werewolf = factory.createNPC("Werewolf", 100, 100, 100);
    NPC* thief = factory.createNPC("Thief", 100, 200, 200);

    // Создаем объекты наблюдатели Observer
    LogObserver logObserver;
    PrintObserver printObserver;

    // Регистрируем Observer на NPC
    bear->registerObserver(&logObserver);
    bear->registerObserver(&printObserver);
    werewolf->registerObserver(&logObserver);
    werewolf->registerObserver(&printObserver);
    thief->registerObserver(&logObserver);
    thief->registerObserver(&printObserver);

    // Создаем объект Battle
    Battle battle;

    // Добавляем NPC на поле боя
    battle.addNPC(bear);
    battle.addNPC(werewolf);
    battle.addNPC(thief);

    // Выводим информацию о персонажах до боя
    std::cout << "NPCs before battle:" << std::endl;
    battle.printNPCs();

    // Запускаем боевой режим
    BattleVisitor battleVisitor;
    battle.startBattle(&battleVisitor);

    // Выводим информацию о персонажах после боя
    std::cout << "NPCs after battle:" << std::endl;
    battle.printNPCs();

    // Удаляем объекты NPC
    delete bear;
    delete werewolf;
    delete thief;

    return 0;
}

