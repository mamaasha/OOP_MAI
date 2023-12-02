#pragma once
#include "NPC.h"

class Thief : public NPC {
public:
    Thief(int health, int x, int y);
    void attack(NPC* target) override; 
    void accept(Visitor* visitor) override; 
};
