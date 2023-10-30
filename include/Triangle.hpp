#pragma once

#include <iostream>
#include <cmath>

#include "figure.hpp"
#include "Validator.hpp"

class Triangle : public Figure {
public:
    Triangle() = default;
    ~Triangle() = default;

    Triangle(Point& a, Point& b, Point& c);

    double getArea()const override;
    std::pair<double, double> getCenter() const override;

    void readVertices(std::istream& is) override;
    void printVertices(std::ostream& os)const override;

    virtual Triangle* clone()const override {
        return new Triangle(*this);
    }
    bool operator!=(const Figure& other)const override; 

    friend std::istream& operator>>(std::istream&, Triangle&);
    friend std::ostream& operator<<(std::ostream&, const Triangle&);
private: 
    Point A, B, C;

};

