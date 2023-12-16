#include "/mnt/c/Users/User/OOP_MAI/include/PrintObserver.h"
#include <iostream>

void PrintObserver::update(const std::string& message) {
    std::cout << message << std::endl;
}