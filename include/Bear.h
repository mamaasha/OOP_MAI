#pragma once
#include "NPC.h"

class Bear : public NPC {
public:
    Bear(int health, int x, int y);
    void attack(NPC* target) override;
    void accept(Visitor* visitor) override;
};
