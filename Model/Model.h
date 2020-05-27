#pragma once
#include "MotorDriver.h"
#include "Pen.h"
#include "Time.h"
#include <vector>
#include <queue>
#include "Dynamic.h"
#include "Drawable.h"
#include <math.h>

struct TaskSet {
	std::queue<Task> X = std::queue<Task>();
	std::queue<Task> Y = std::queue<Task>();
};

class Model
{
private:
	Square *xPivot, *yPivot;
	MotorDriver *XDriver, *YDriver;
	ServoDriver *servo;
	Pen *pen;
	bool initialized = false;

public:
	Model();
	~Model();
	std::vector<Dynamic *> getDynamicObjects();
	std::vector<Shape *> getDrawables();
	void Init();

private:
	std::queue<Task> MakeCurve(int definition, float time, float X, float Y, bool invertY, bool invertX);
	TaskSet MakeCircle();
};

bool test_Model();
