#pragma once
#include "Visitor.h"

class BattleVisitor : public Visitor {
public:
    void visit(NPC* npc) override;
};