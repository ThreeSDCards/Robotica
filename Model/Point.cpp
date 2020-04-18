#include "Point.h"

Point::Point(float x, float y)
	: X(x), Y(y) {}

Point Point::Add(float x, float y)
{
	return Point(X + x, Y + y);
}

bool test_Point()
{
	try
	{
		Point p(3, 0);

		//Test Add
		if (p.Add(5, 4).X != 8 || p.Add(0, -2).Y != -2)
			throw "POINT ERROR (ADD)";
		return true;
	}
	catch (const char *e)
	{
		return false;
	}
}