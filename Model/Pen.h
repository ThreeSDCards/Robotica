#pragma once
#include "Square.h"
#include "ServoDriver.h"
#include "Dynamic.h"

class Pen : public Square, public Dynamic
{

private:
	Shape *PivotX, *PivotY;
	ServoDriver *servo;

public:
	Pen(Shape *X, Shape *Y, ServoDriver *servo);
	void Routine(float) override;
};
