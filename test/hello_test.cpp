#include <gtest/gtest.h>
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include <cmath> 

TEST(TriangleTest1, GetArea) {
  Point A(0.0, 0.0);
  Point B(3.0, 4.0);
  Point C(6.0, 0.0);
  Triangle triangle(A, B, C);

  double expected_area = 12.0;
  double actual_area = triangle.getArea();

  EXPECT_NEAR(expected_area, actual_area, 0.0001); 
}


TEST(TriangleTest3, GetCenter) { //робит
  Point A(0.0, 0.0);
  Point B(3.0, 4.0);
  Point C(6.0, 0.0);
  Triangle triangle(A, B, C);

  std::pair<double, double> expected_center(3.0, 1.333333);
  std::pair<double, double> actual_center = triangle.getCenter();

  EXPECT_NEAR(expected_center.first, actual_center.first, 0.0001);
  EXPECT_NEAR(expected_center.second, actual_center.second, 0.0001);
}


TEST(TriangleTest4, WriteTriangleVerticesToStream) {
    std::ostringstream oss;

    Point a(0.0, 0.0);
    Point b(1.0, 0.0);
    Point c(0.0, 1.0);

    Triangle triangle(a, b, c);
    triangle.printVertices(oss);

    std::string expectedOutput = "(0,0) (1,0) (0,1)";

    EXPECT_EQ(expectedOutput, oss.str());
}

TEST(RectangleTest5, CalculateRectangleArea) {
    Point a(0.0, 0.0);
    Point b(1.0, 0.0);
    Point c(1.0, 2.0);
    Point d(0.0, 2.0);

    Rectangle rectangle(a, b, c, d);

    double expectedArea = 2;

    EXPECT_NEAR(expectedArea, rectangle.getArea(), 0.0001);
}

TEST(RectangleTest6, CalculateRectangleCenter) {
    Point a(0.0, 0.0);
    Point b(1.0, 0.0);
    Point c(1.0, 1.0);
    Point d(0.0, 1.0);

    Rectangle rectangle(a, b, c, d);

    double expectedCenterX = 0.5;
    double expectedCenterY = 0.5;

    EXPECT_NEAR(expectedCenterX, rectangle.getCenter().first, 0.0001);
    EXPECT_NEAR(expectedCenterY, rectangle.getCenter().second, 0.0001);
}

TEST(RectangleTest7, WriteRectangleVerticesToStream) {
    std::ostringstream oss;

    Point a(0.0, 0.0);
    Point b(1.0, 0.0);
    Point c(1.0, 1.0);
    Point d(0.0, 1.0);

    Rectangle rectangle(a, b, c, d);
    rectangle.printVertices(oss);

    std::string expectedOutput = "(0,0) (1,0) (1,1) (0,1)";

    EXPECT_EQ(expectedOutput, oss.str());
}

TEST(RectangleTest8, CalculateRectangleArea) {
    Point a(0.0, 0.0);
    Point b(1.0, 0.0);
    Point c(1.0, 2.0);
    Point d(0.0, 2.0);

    Rectangle rectangle(a, b, c, d);

    double expectedArea = 2;

    EXPECT_EQ(expectedArea, rectangle.getArea());
}

TEST(TriangleTest9, NotEqualOperator) {
  Point A(0.0, 0.0);
  Point B(3.0, 4.0);
  Point C(6.0, 0.0);
  Triangle triangle1(A, B, C);
  Triangle triangle2(A, B, C);

  EXPECT_FALSE(triangle1 != triangle2);
}

TEST(TriangleTest10, NotEqualOperator_DifferentTriangles) {
  Point A1(0.0, 0.0);
  Point B1(3.0, 4.0);
  Point C1(6.0, 0.0);
  Triangle triangle1(A1, B1, C1);

  Point A2(0.0, 0.0);
  Point B2(3.0, 2.0);
  Point C2(6.0, 0.0);
  Triangle triangle2(A2, B2, C2);

  EXPECT_TRUE(triangle1 != triangle2);
}

TEST(SquareTest11, CalculateSquareCenter) {
    Point a(0.0, 0.0);
    Point b(1.0, 0.0);
    Point c(1.0, 1.0);
    Point d(0.0, 1.0);

    Square square(a, b, c, d);

    double expectedCenterX = 0.5;
    double expectedCenterY = 0.5;

    EXPECT_NEAR(expectedCenterX, square.getCenter().first, 0.0001);
    EXPECT_NEAR(expectedCenterY, square.getCenter().second, 0.0001);
}

TEST(SquareTest11, CalculateSquareArea) {
    Point a(0.0, 0.0);
    Point b(1.0, 0.0);
    Point c(1.0, 2.0);
    Point d(0.0, 2.0);

    Square square(a, b, c, d);

    double expectedArea = 2;
    double area = square.getArea();

    EXPECT_EQ(expectedArea, area);
}

