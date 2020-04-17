#pragma once
#include "Point.h"
#include "Drawable.h"

class Shape : Drawable
{

public:
	Point origin;

	Point Orig();
};