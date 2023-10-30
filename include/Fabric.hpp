#pragma once
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"

class Fabric {
public:
    virtual Fabric* creat(Point* p)  = 0;    
    virtual ~Fabric();

};

class FabricTriangle : public Fabric {
public:
    Fabric* create(Point* p) override;    
};

class FabricRctangle : public Fabric {
public:
    Fabric* create(Point* p) override;   
};

class FabricSquare : public Fabric{
public:
    Fabric* creat(Point* p) override; 
};