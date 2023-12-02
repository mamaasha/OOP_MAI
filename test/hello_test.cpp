#include <gtest/gtest.h>
#include "/mnt/c/Users/User/OOP_MAI/include/NPCFactory.h"
#include "NPC.h"
#include "/mnt/c/Users/User/OOP_MAI/include/Battle.h"
#include "/mnt/c/Users/User/OOP_MAI/include/BattleVisitor.h"

TEST(BattleTest, BattleWithNoNPCs) {
    Battle battle;
    BattleVisitor battleVisitor;
    ASSERT_NO_THROW(battle.startBattle(&battleVisitor)); // Проверяем, что бой не вызывает исключений при отсутствии NPC
}

TEST(BattleTest, BattleWithOneNPC) {
    Battle battle;
    NPCFactory factory;
    NPC* bear = factory.createNPC("Bear", 100, 0, 0);
    battle.addNPC(bear);
    BattleVisitor battleVisitor;
    ASSERT_NO_THROW(battle.startBattle(&battleVisitor)); // Проверяем, что бой не вызывает исключений при наличии только одного NPC
}

TEST(BattleTest, CorrectNPCHealthAfterBattle) {
    Battle battle;
    NPCFactory factory;
    NPC* bear = factory.createNPC("Bear", 100, 0, 0);
    NPC* werewolf = factory.createNPC("Werewolf", 100, 100, 100);
    battle.addNPC(bear);
    battle.addNPC(werewolf);
    BattleVisitor battleVisitor;
    battle.startBattle(&battleVisitor);
    EXPECT_GE(bear->getHealth(), 0); // Проверяем, что здоровье NPC после боя неотрицательное
    EXPECT_GE(werewolf->getHealth(), 0); // Проверяем, что здоровье NPC после боя неотрицательное
}

// Другие тесты, проверяющие различные аспекты боя, добавления и удаления NPC и т.д.
