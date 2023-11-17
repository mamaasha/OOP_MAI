#pragma once

#include "figure.hpp"
#include "Validator.hpp"

class Rectangle : public Figure {
public:
    Rectangle();
    ~Rectangle() = default;

    Rectangle(const Point& a, const Point& b, const Point& c, const Point& d);

    double getArea()const override;
    std::pair<double, double> getCenter() const override;

    void readVertices(std::istream& is) override;
    void printVertices(std::ostream& os)const override;

    bool operator!=(const Figure& other) const override;
    virtual Rectangle* clone()const override {
        return new Rectangle(*this);
    }

    friend std::istream& operator>>(std::istream&, Rectangle&);
    friend std::ostream& operator<<(std::ostream&, const Rectangle&);

protected:
    Point A, B, C, D;
};

