#pragma once
#include "MotorDriver.h"
#include "Pen.h"
#include "Time.h"
#include <vector>
#include "Dynamic.h"
#include "Drawable.h"

class Model
{
private:
	Square *xPivot, *yPivot;
	MotorDriver *XDriver, *YDriver;
	Pen *pen;
	bool initialized = false;

public:
	Model();
	~Model();
	std::vector<Dynamic *> getDynamicObjects();
	std::vector<Shape *> getDrawables();
	void Init();
};

bool test_Model();
