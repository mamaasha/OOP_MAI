#pragma once
#include <string>
#include "Observer.h"

class PrintObserver : public Observer {
public:
    void update(const std::string& message) override;
};

