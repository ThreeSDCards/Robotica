#pragma once
#include "Shape.h"
#include <vector>

class Square : Shape
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
};

//TODO Square test
//TODO Shape test