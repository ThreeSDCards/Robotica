#pragma once
#include "MotorDriver.h"
#include "Pen.h"
#include <vector>

class Model
{

private:
	MotorDriver *XDriver, *YDriver;
	Pen *pen;

public:
	Model();
	~Model();
	std::vector<Module *> getDynamicObjects();

	void Init();
};
