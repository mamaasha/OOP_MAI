
#include "/mnt/c/Users/User/OOP_MAI/include/point.hpp"
#include <cmath>
#include <string>

template <typename T>
Point<T>::Point() : x_(0.0), y_(0.0) {}

template <typename T>
Point<T>::Point(T x, T y) : x_(x), y_(y) {
    // std::string x_str = std::to_string(x);
    // std::string y_str = std::to_string(y);
    // ValidatorPoint::validatePoint(x_str, y_str);
}

template <typename T>
Point<T>::Point(std::istream& is) {
    is >> x_ >> y_;
}

template <typename T>
bool Point<T>::operator!=(const Point& other) const {
    return x_ != other.x_ || y_ != other.y_;
}

template <typename T>
T Point<T>::distance(const Point& other)const {
    T length_x = other.x_ - x_;
    T length_y = other.y_ - y_;
    return std::sqrt(length_x*length_x + length_y*length_y);
}

template <typename T>
std::istream& operator>>(std::istream& is, Point<T>& p) {
    is >> p.x_ >> p.y_;
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& p) {
    os << "(" << p.x_ <<"," << p.y_ << ")";
    return os;
}

template <typename T>
T Point<T>::getX() const { 
    return x_; 
}
template <typename T>
T Point<T>::getY() const { 
    return y_; 
}

template <typename T>
bool Point<T>::operator==(const Point& other) const {
    return x_ == other.x_ && y_ == other.y_;
}