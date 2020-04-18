#pragma once
#include "Shape.h"
#include <vector>

class Square : public Shape
{
    std::vector<Point> points;
    float size;

public:
    Square();
    /*
         *  Creates square at pos, size is length of each side.
         */
    Square(const Point &pos, float size);
    Point &TL();
    Point &TR();
    Point &BL();
    Point &BR();

    std::vector<Point> &Points();
    virtual void Draw();
};

bool test_Square();

bool test_Shape();