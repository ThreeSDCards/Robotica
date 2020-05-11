#pragma once
#include "Point.h"
#include "GL/glew.h"
#include <GL/glut.h>

class Shape
{
	Point orig;

public:
	//Abstract class
	virtual ~Shape(){};
	virtual void Draw() = 0;
	void Move(float x, float y);
	void SetOrig(const Point &pos);
	Point GetOrig();
};

bool test_Shape();