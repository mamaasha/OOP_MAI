#pragma once

#include <vector>

#include "figure.hpp"

class FigureArray {
public:
    FigureArray() = default;
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other)noexcept;
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(const FigureArray&& other)noexcept; 
    bool operator==(const FigureArray& other)const; 
    ~FigureArray();

    void addFigure(Figure* figure);
    void deleteFigure(int index);
    void printCenters() const;
    
    double getTotalArea()const;
    
    int size()const;

private:
    std::vector<Figure*> figures_;

};

