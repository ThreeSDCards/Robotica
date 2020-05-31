#pragma once
#include "MotorDriver.h"
#include "Pen.h"
#include "Time.h"
#include <vector>
#include <queue>
#include "Dynamic.h"
#include "Drawable.h"
#include <math.h>


#define M_PI            3.14159265358979323846
#define CIRCLEDEF		20

struct TaskSet{
	std::queue<Task> X = std::queue<Task>();
	std::queue<Task> Y = std::queue<Task>();
	std::queue<Task> Z = std::queue<Task>();
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
	TaskSet DrawCircle(float radius, float time);
};

bool test_Model();
