#include "Shape.h"

Point Shape::Orig()
{
	return origin;
}

void Shape::Move(float x, float y)
{
	origin.X += x;
	origin.Y += y;
}