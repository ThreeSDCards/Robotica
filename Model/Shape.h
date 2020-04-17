#pragma once
#include "Point.h"
#include "Drawable.h"

class Shape : Drawable
{

public:
	//Abstract class
	virtual ~Shape(){};
	Point origin;

	Point Orig();
	void Move(float x, float y);
};