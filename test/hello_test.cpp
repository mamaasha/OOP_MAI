#include <gtest/gtest.h>
#include "/mnt/c/Users/User/OOP_MAI/include/NPCFactory.h"
#include "NPC.h"
#include "/mnt/c/Users/User/OOP_MAI/include/Battle.h"
#include "/mnt/c/Users/User/OOP_MAI/include/BattleVisitor.h"

TEST(BattleTest, BattleWithNoNPCs) { // нет NPC
    Battle battle;
    BattleVisitor battleVisitor;
    ASSERT_NO_THROW(battle.startBattle(&battleVisitor));
}

TEST(BattleTest, BattleWithOneNPC) { // один NPC
    Battle battle;
    NPCFactory factory;
    NPC* bear = factory.createNPC("Bear", 100, 0, 0);
    battle.addNPC(bear);
    BattleVisitor battleVisitor;
    ASSERT_NO_THROW(battle.startBattle(&battleVisitor)); 
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
    EXPECT_GE(bear->getHealth(), 0); 
    EXPECT_GE(werewolf->getHealth(), 0); 
}
