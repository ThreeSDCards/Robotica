#pragma once
#include "Square.h"

class PivotPoint : public Square
{
    const float size = 0.05;

public:
    PivotPoint(const Point &pos);
};