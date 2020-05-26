#include "Shape.h"

void Shape::Move(float x, float y)
{
	SetOrig({GetOrig().X + x, GetOrig().Y + y});
}

void Shape::SetOrig(const Point &pos)
{
	orig = pos;
}

Point Shape::GetOrig() const
{
	return orig;
}