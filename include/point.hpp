#pragma once

// #include "ValidatorPoints.hpp"
#include <iostream>
#include <cmath>

template <typename T>
class Point {
public:
    Point();
    Point(std::istream& is);
    Point(T x, T y);

    bool operator!=(const Point& other) const;
    bool operator==(const Point& other) const;

    T distance(const Point& other)const;
    T getX() const;
    T getY() const;

    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& p);

private:
    T x_, y_;
};
