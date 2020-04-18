#pragma once
#include "Square.h"
#include "PivotPoint.h"
#include "ServoDriver.h"

class Pen : Square
{

private:
	PivotPoint *PivotX, *PivotY;
	ServoDriver *servo;
	Pen(PivotPoint *X, PivotPoint *Y, ServoDriver *servo);
};