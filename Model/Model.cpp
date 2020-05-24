#include "Model.h"

Model::Model()
	: XDriver(nullptr), YDriver(nullptr), pen(nullptr) {}

Model::~Model()
{
	delete XDriver, YDriver, pen;
}

std::vector<Module *> Model::getDynamicObjects()
{
	std::vector<Module *> out;
	out.push_back(XDriver);
	out.push_back(YDriver);
	return out;
}

void Model::Init()
{
	xPivot = new Square({-0.55f, 0.5f}, 0.05f);
	yPivot = new Square({-0.5f, 0.45f}, 0.05f);
	XDriver = new MotorDriver(*xPivot, true);
	YDriver = new MotorDriver(*yPivot, false);

	ServoDriver *ZDriver = new ServoDriver();
	pen = new Pen(xPivot, yPivot, ZDriver);

	//v0.0.1
	Task task = Task();
	task.Time = 1000;
	task.Dest = 0.5f;
	XDriver->Do(task);
	task.Time = 1000;
	task.Dest = -0.5f;
	YDriver->Do(task);
}

std::vector<Shape *> Model::getDrawables()
{
	std::vector<Shape *> out = std::vector<Shape *>();
	out.push_back(xPivot);
	out.push_back(yPivot);
	return out;
}

bool test_Model()
{
	try
	{
	}
	catch (const std::exception &e)
	{
		return false;
	}
	return true;
}