#include "/mnt/c/Users/User/OOP_MAI/include/LogObserver.h"
#include <iostream>
#include <fstream>

void LogObserver::update(const std::string& message) {
    std::ofstream logFile;
    logFile.open("log.txt", std::ios_base::app);
    logFile << message << std::endl;
    logFile.close();
}
