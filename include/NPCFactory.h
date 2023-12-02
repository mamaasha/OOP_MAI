#pragma once

#include <string>
#include "NPC.h"

class NPCFactory {
public:
    NPC* createNPC(const std::string& type, int health, int x, int y);
};

