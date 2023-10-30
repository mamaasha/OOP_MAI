
#include <iostream>
#include <cmath>

#include "Triangle.hpp"
#include "Validator.hpp"
// Triangle::Triangle() : A(0.0, 0.0), B(0.0, 0.0), C(0.0, 0.0) {}

Triangle::Triangle(Point& a, Point& b, Point& c) : A(a), B(b), C(c) {
    // Validator::validateTriangle(A, B, C);
}

double Triangle:: getArea()const {  
    double ab = A.distance(B);
    double ac = A.distance(C);
    double bc = B.distance(C);
    double halfPerimeter = (ab + ac + bc) / 2.0;
    return std::sqrt(halfPerimeter * (halfPerimeter - ab) *
                (halfPerimeter - bc) * (halfPerimeter - ac));
}

std::pair<double, double> Triangle::getCenter()const {
    double center_x = (A.getX() + B.getX()  + C.getX()) / 3.0;
    double center_y = (A.getY()  + B.getY() + C.getY()) / 3.0;
    return std::make_pair(center_x, center_y);
}

void Triangle::readVertices(std::istream& is) {
    is >> A >> B >> C;
}

void Triangle::printVertices(std::ostream& os)const {
    os << A << " " << B << " " << C;
}

// Triangle::~Triangle() = default;

std::istream& operator>>(std::istream& is, Triangle& triangle) {
    triangle.readVertices(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Triangle& triangle) {
    triangle.printVertices(os);
    return os;
}

bool Triangle::operator!=(const Figure& other)const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    
    if (otherTriangle == nullptr)
        return true;
    return A!= otherTriangle -> A || B!= otherTriangle -> B || C!= otherTriangle -> C;
}