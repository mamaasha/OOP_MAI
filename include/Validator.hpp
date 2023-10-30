#pragma once

#include <stdexcept>
#include <limits>

class Validator {
public:
    static void validateTriangle(const Point& a, const Point& b, const Point& c) {
        if(a == b || b == c || c == a)
            throw std::invalid_argument("Triangle vertices must be different");
        if(slope(a, b) == slope(a, c))
            throw std::invalid_argument("Triangle vertices must not be collinear"); 
        
    }

    static void validateRectangle(const Point& a, const Point& b, const Point& c, const Point& d) {
        if (a == b || b == c || c == d || d == a) 
            throw std::invalid_argument("Rectangle vertices must be distinct");
        if (!isParallel(a, c, b, d)) 
            throw std::invalid_argument("Rectangle sides must be parallel");
        double ab = a.distance(b);
        double cd = c.distance(d);
        double bc = b.distance(c);
        double da = d.distance(a);
        double ac = a.distance(c);
        double bd = d.distance(b);
        if ((ab * ab + bc * bc != ac * ac) && (ab * ab + cd * cd != bd * bd)) //Пифагор
            throw std::invalid_argument("Rectangle angles must be 90 degrees");
    }

    static void validateSquare(const Point& a, const Point& b, const Point& c, const Point& d) {
        validateRectangle(a, b, c, d);
        double ab = a.distance(b);
        double ac = a.distance(c);

        if (ab != ac) {
            throw std::invalid_argument("Square sides must be equal");
        }
    }
private:
    // наклон
    static double slope(const Point& p1, const Point& p2) {
        if(p1.getX() == p2.getX())
            return std::numeric_limits<double>::infinity();
        return (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());    
    }
    static bool isParallel(const Point& a, const Point& b, const Point& c, const Point& d) {
        return slope(a, b) == slope(c, d);
    }
};

