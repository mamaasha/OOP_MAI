#pragma once

#include <iostream>
#include <vector>

#include "point.hpp"
// #include "Validator.hpp"

class Figure {
public:
    virtual ~Figure() = default;

    virtual double getArea()const = 0;
    virtual std::pair<double, double> getCenter()const = 0;

    virtual void printVertices(std::ostream& os)const = 0;
    virtual void readVertices(std::istream& is) = 0;

    virtual Figure* clone()const = 0;
    virtual bool operator!=(const Figure& other)const {
        return !(this == &other); ////дописать, если разная ссылка
    };

    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, Figure& figure);

};

