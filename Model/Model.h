#pragma once
#include "MotorDriver.h"
#include "Pen.h"
#include "Time.h"
#include <vector>
#include "Drawable.h"

class Model
{

private:
	Square *xPivot, *yPivot;
	MotorDriver *XDriver, *YDriver;
	Pen *pen;
	Time *timer;

public:
	Model();
	~Model();
	std::vector<Module *> getDynamicObjects();
	std::vector<Shape *> getDrawables();

	void Init();
};
