#include "/mnt/c/Users/User/OOP_MAI/include/NPC.h"
#include "/mnt/c/Users/User/OOP_MAI/include/Bear.h"
#include "/mnt/c/Users/User/OOP_MAI/include/Thief.h"
#include "/mnt/c/Users/User/OOP_MAI/include/Werewolf.h"
#include "Visitor.h"

NPC::NPC(const std::string& name, int health, int x, int y)
    : name(name), health(health), x(x), y(y) {}

void NPC::registerObserver(Observer* observer) {
    observers.push_back(observer);
}

void NPC::notifyObservers(const std::string& message) {
    for (Observer* observer : observers) {
        observer->update(message);
    }
}

const std::string& NPC::getName() const {
    return name;
}

int NPC::getHealth() const {
    return health;
}

int NPC::getX() const {
    return x;
}

int NPC::getY() const {
    return y;
}

void NPC::setHealth(int health) {
    this->health = health;
}

void NPC::setX(int x) {
    this->x = x;
}

void NPC::setY(int y) {
    this->y = y;
}

void Bear::accept(Visitor* visitor) {
    visitor->visit(this);
}

void Werewolf::accept(Visitor* visitor) {
    visitor->visit(this);
}

void Thief::accept(Visitor* visitor) {
    visitor->visit(this);
}

