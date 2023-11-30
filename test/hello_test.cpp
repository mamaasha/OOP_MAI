#include "gtest/gtest.h"
#include "Queue.h"
#include "factorial.h"
#include <map>

int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

TEST(MyQueueTest, PushAndPop) {
    MyQueue<int, 5, MyAllocator<int, 5>> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.pop();
    EXPECT_EQ(myQueue.front(), 20);
}

TEST(MyQueueTest, FrontAndEmpty) {
    MyQueue<int, 5, MyAllocator<int, 5>> myQueue;
    EXPECT_TRUE(myQueue.empty());
    myQueue.push(10);
    EXPECT_EQ(myQueue.front(), 10);
    EXPECT_FALSE(myQueue.empty());
}

TEST(MyQueueTest, Exceptions) {
    MyQueue<int, 2, MyAllocator<int, 2>> myQueue;
    myQueue.push(10);
    myQueue.push(20);
    EXPECT_THROW(myQueue.push(30), std::out_of_range);
    myQueue.pop();
    myQueue.pop();
    EXPECT_THROW(myQueue.pop(), std::out_of_range);
    EXPECT_THROW(myQueue.front(), std::out_of_range);
}

TEST(MyMapTest, FactorialValues) {
    std::map<int, int, std::less<int>, MyAllocator<std::pair<const int, int>, 10>> myMap;
    for (int i = 0; i < 5; ++i) {
        myMap[i] = factorial(i);
    }
    EXPECT_EQ(myMap[0], 1);
    EXPECT_EQ(myMap[1], 1);
    EXPECT_EQ(myMap[2], 2);
    EXPECT_EQ(myMap[3], 6);
    EXPECT_EQ(myMap[4], 24);
}
