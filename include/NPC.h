#pragma once

#include <string>
#include <vector>
#include "Observer.h"
#include "Visitor.h"

class Visitor;

class NPC { 

public:
    NPC(const std::string& name, int health, int x, int y);

    void registerObserver(Observer* observer);
    void notifyObservers(const std::string& message);

    virtual void attack(NPC* target) = 0;

    const std::string& getName() const;
    int getHealth() const;
    int getX() const;
    int getY() const;

    void setHealth(int health);
    void setX(int x);
    void setY(int y);

    virtual void accept(Visitor* visitor) = 0;

private:
    std::string name;
    int health;
    int x;
    int y;
    std::vector<Observer*> observers; 
};

