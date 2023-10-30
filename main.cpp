#include <iostream>
#include <vector>

// #include "array.hpp"
#include "Triangle.hpp"
// #include "Square.hpp"
// #include "Rectangle.hpp"

int main() {
    // FigureArray array;

    Triangle t;
    std::cin >> t;

    std::cout << t.getArea() << std::endl;


//     for (int i = 0; i < n; ++i) {
//         std::cout << "Enter the type of figure (0 - Triangle, 1 - Square, 2 - Rectangle): ";
//         int type;
//         std::cin >> type;

//         switch (type) {
//             case 0: {
//                 std::cout << "Enter the vertices of the triangle: ";
//                 Triangle* triangle = new Triangle();
//                 std::cin >> *triangle;
//                 array.addFigure(triangle);
//                 break;
//             }
//             case 1: {
//                 std::cout << "Enter the vertices of the square: ";
//                 Square* square = new Square();
//                 std::cin >> *square;
//                 array.addFigure(square);
//                 break;
//             }
//             case 2: {
//                 std::cout << "Enter the vertices of the rectangle: ";
//                 Rectangle* rectangle = new Rectangle();
//                 std::cin >> *rectangle;
//                 array.addFigure(rectangle);
//                 break;
//             }
//             default:
//                 std::cout << "Invalid figure type!" << std::endl;
//                 break;
//         }
//     }

//     array.printCenters();
//     std::cout << "Total area: " << array.getTotalArea() << std::endl;

//     std::cout << "Enter the index of the figure to delete: ";
//     int index;
//     std::cin >> index;

//     array.deleteFigure(index);

//     array.printCenters();
//     std::cout << "Total area: " << array.getTotalArea() << std::endl;

    return 0;
}
