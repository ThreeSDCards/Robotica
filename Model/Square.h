#pragma once
#include "Shape.h"

class Square : public Shape
{
    float size;

public:
    Square();
    /*
         *  Creates square at pos, size is length of each side.
         */
    Square(const Point &pos, float size);
    Point TL();
    Point TR();
    Point BL();
    Point BR();
    void Draw() override;
};

bool test_Square();