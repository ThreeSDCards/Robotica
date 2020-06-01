#pragma once
#include "Point2.h"
#include "Drawable.h"
#ifdef _WIN32
#include "../GL/glew.h"
#include "../GL/glut.h"
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

class Shape : public Drawable
{
	Point orig;

public:
	//Abstract class
	virtual ~Shape(){};
	void Move(float x, float y);
	void SetOrig(const Point2 &pos);
	Point2 GetOrig() const;
};

bool test_Shape();
