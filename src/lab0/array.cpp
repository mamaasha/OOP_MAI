#include <vector>

#include "array.hpp"

FigureArray::FigureArray(const FigureArray& other) {
    for(const auto& figure : other.figures_)
        figures_.push_back(figure->clone());
}

FigureArray::FigureArray(FigureArray&& other)noexcept {
    figures_ = std::move(other.figures_);
}

FigureArray& FigureArray::operator=(const FigureArray& other){
    if(this != &other) {
        for(const auto& figure : figures_)
            delete figure;
        figures_.clear();
        for(const auto& figure : other.figures_)
            figures_.push_back(figure->clone());;     
    }
    return *this;
}
FigureArray& FigureArray::operator=(const FigureArray&& other)noexcept {
    if(this != &other) {
        for(const auto& figure : figures_)
            delete figure;
        figures_.clear();
        figures_ = std::move(other.figures_);
    }
    return *this;
}
bool FigureArray::operator==(const FigureArray& other)const {
    if(figures_.size() != other.figures_.size())
        return false;

    for(size_t i = 0; i < figures_.size(); ++i) {
        if(*figures_[i] != *other.figures_[i])
            return false;
    }
    return true;
}

FigureArray::~FigureArray() {
    for(auto figure : figures_)
        delete figure;

    // delete[] figures_;
}

void FigureArray::addFigure(Figure* figure) {
    figures_.push_back(figure);    
}

void FigureArray::deleteFigure(int index) {
    if(index >= 0 && index < figures_.size()) {
        delete figures_[index];
        figures_.erase(figures_.begin() + index);
    }      
}

void FigureArray::printCenters()const {
    for(const auto& figure : figures_) 
        std::cout << "Center: " << figure->getCenter().first << 
        ", " << figure->getCenter().second << std::endl;
}

double FigureArray::getTotalArea() const {
    double totalArea = 0.0;
    for(const auto& figure : figures_)
        totalArea += figure->getArea();
    return totalArea;
}

int FigureArray::size()const {
    return figures_.size();
}