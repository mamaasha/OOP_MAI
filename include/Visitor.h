#pragma once

#include "/mnt/c/Users/User/OOP_MAI/include/NPC.h"

class NPC;

class Visitor {
public:
    virtual void visit(NPC* npc) = 0;
};