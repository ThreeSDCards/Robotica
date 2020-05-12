#pragma once
#include "MotorDriver.h"
#include "Pen.h"
#include <vector>

class Model {

private:
	MotorDriver* XDriver,_YDriver;
	Pen* pen;

public:
	std::vector<Module> getDynamicObjects();

	void Init();
};

