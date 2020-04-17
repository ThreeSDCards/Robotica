#include "Point.h"

Point::Point(float x, float y)
	: X(x), Y(y) {}

Point Point::Add(float x, float y)
{
	return Point(X + x, Y + y);
}
