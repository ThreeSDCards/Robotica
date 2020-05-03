#pragma once
#include "Square.h"
#include "ServoDriver.h"

class Pen : public Square
{

private:
	Shape *PivotX, *_PivotY;
	ServoDriver *servo;
};
