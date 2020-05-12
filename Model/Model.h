#pragma once
#include "MotorDriver.h"
#include "Pen.h"
#include "Time.h"
#include <vector>

class Model
{

private:
	MotorDriver *XDriver, *YDriver;
	Pen *pen;
	Time *timer;

public:
	Model();
	~Model();
	std::vector<Module *> getDynamicObjects();

	void Init();
};
