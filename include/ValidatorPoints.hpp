#pragma once

#include <iostream>
#include <string>

#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "array.hpp"

class ValidatorPoint {
public:
    static void validatePoint(const std::string& x_str, const std::string& y_str) {
        try {
            double x = std::stod(x_str);
            double y = std::stod(y_str);
        }catch (const std::invalid_argument& e) {
            throw std::invalid_argument("Incorrect coordinate format");
        }
    }
};