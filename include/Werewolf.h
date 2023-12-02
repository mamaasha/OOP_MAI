#pragma once
#include "NPC.h"

class Werewolf : public NPC {
public:
    Werewolf(int health, int x, int y);
    void attack(NPC* target) override;
    void accept(Visitor* visitor) override;
};