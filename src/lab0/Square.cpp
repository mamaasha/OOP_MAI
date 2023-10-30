#include "/mnt/c/Users/User/OOP_MAI/include/Square.hpp"

Square::Square() = default;

Square::Square(const Point& a, const Point& b, const Point& c, const Point& d) : Rectangle(a, b, c, d) {
    // Validator::validateSquare(a, b, c, d);
}
