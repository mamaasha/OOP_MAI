#pragma once

#include <iostream>
// #include "ValidatorPoints.hpp"

class Point {
public:
    Point();
    Point(std::istream& is);
    Point(double x, double y);
    bool operator!=(const Point& other) const;
    bool operator==(const Point& other) const;

    double distance(const Point& other)const;
    double getX() const;
    double getY() const;

    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

private:
    double x_, y_;
};
