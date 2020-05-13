#pragma once
#include "Square.h"
#include "ServoDriver.h"

class Pen : public Square
{

private:
	Shape *PivotX, *PivotY;
	ServoDriver *servo;

public:
	Pen(Shape *X, Shape *Y, ServoDriver *servo);
};
