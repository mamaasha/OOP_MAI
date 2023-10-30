#include <iostream>
#include <cmath>

#include "/mnt/c/Users/User/OOP_MAI/include/Rectangle.hpp"
// #include "Validator.hpp"

Rectangle::Rectangle() : A(0.0, 0.0), B(0.0, 0.0), C(0.0, 0.0), D(0.0, 0.0) {}

Rectangle::Rectangle(const Point& a, const Point& b, const Point& c, const Point& d) : A(a), B(b), C(c), D(d) {
    // Validator::validateRectangle(A, B, C, D);
}

void Rectangle::Rectangle::readVertices(std::istream& is) {
    is >> A >> B >> C >> D;
}

void Rectangle::printVertices(std::ostream& os)const {
    os << A << " " << B << " " << C << " " << D;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
    rectangle.readVertices(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) {
    rectangle.printVertices(os);
    return os;
}

double Rectangle::getArea()const {  
    double ab = A.distance(B);
    double bc = B.distance(C);
    return ab * bc;
}

std::pair<double, double> Rectangle::getCenter()const {
    double center_x = (A.getX() + B.getX()  + C.getX() + D.getX()) / 4.0;
    double center_y = (A.getY()  + B.getY() + C.getY()+ D.getY()) / 4.0;
    return std::make_pair(center_x, center_y);
}

bool Rectangle::operator!=(const Figure& other) const {
    const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
    if (otherRectangle == nullptr)
        return true;
    // Сравнение вершин прямоугольников
    return (A != otherRectangle->A) || (B != otherRectangle->B) || (C != otherRectangle->C) || (D != otherRectangle->D);
}
