#pragma once
#include <string>
#include "Observer.h"

class LogObserver : public Observer {
public:
    void update(const std::string& message) override;
};

