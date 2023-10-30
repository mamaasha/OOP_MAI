
#include "/mnt/c/Users/User/OOP_MAI/include/point.hpp"
#include <cmath>
#include <string>

Point::Point() : x_(0.0), y_(0.0) {}

Point::Point(double x, double y) : x_(x), y_(y) {
    // std::string x_str = std::to_string(x);
    // std::string y_str = std::to_string(y);
    // ValidatorPoint::validatePoint(x_str, y_str);
}

Point::Point(std::istream& is) {
    is >> x_ >> y_;
}

bool Point::operator!=(const Point& other) const {
    return x_ != other.x_ || y_ != other.y_;
}

double Point::distance(const Point& other)const {
    double length_x = other.x_ - x_;
    double length_y = other.y_ - y_;
    return std::sqrt(length_x*length_x + length_y*length_y);
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x_ >> p.y_;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x_ <<"," << p.y_ << ")";
    return os;
}

double Point::getX() const { 
    return x_; 
}
double Point::getY() const { 
    return y_; 
}

bool Point::operator==(const Point& other) const {
    return x_ == other.x_ && y_ == other.y_;
}