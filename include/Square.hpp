#pragma once

//#include "Validator.hpp"
#include "Rectangle.hpp"

class Square : public Rectangle {
public:
    Square();
    ~Square() = default;
    Square(const Point& a, const Point& b, const Point& c, const Point& d);
};

