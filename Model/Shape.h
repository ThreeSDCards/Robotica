#pragma once
#include "Point.h"
#include "Drawable.h"

class Shape : Drawable
{
	Point orig;

public:
	//Abstract class
	virtual ~Shape(){};
	void Move(float x, float y);
	void SetOrig(const Point &pos);
	Point GetOrig();
};