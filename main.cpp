#include "Queue.h"
#include <iostream>
#include <map>

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main() {
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>, 10>> myMap;

    for (int i = 0; i < 10; ++i) {
        myMap[i] = factorial(i);
    }

    for (const auto& pair : myMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    MyQueue<int, 10, MyAllocator<int, 10>> myQueue;

    for (int i = 0; i < 10; ++i) {
        myQueue.push(i);
    }
    
    while (!myQueue.empty()) {
        if (myQueue.get_size() > 1) {
            std::cout << myQueue.front() << " ";
        } else {
            std::cout << myQueue.front();
        }
        myQueue.pop();
    }

    return 0;
}

