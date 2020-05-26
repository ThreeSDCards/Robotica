#include "Model.h"

Model::Model()
	: XDriver(nullptr), YDriver(nullptr), pen(nullptr) {}

Model::~Model()
{
	delete XDriver, YDriver, pen;
}

std::vector<Dynamic *> Model::getDynamicObjects()
{
	if (initialized)
	{
		std::vector<Dynamic *> out;
		out.push_back(XDriver);
		out.push_back(YDriver);
		out.push_back(pen);
		return out;
	}
	else
	{
		throw "Model uninitialized";
		return std::vector<Dynamic *>();
	}
}

void Model::Init()
{
	xPivot = new Square({-0.5f, 0.5f}, 0.05f);
	yPivot = new Square({-0.5f, 0.5f}, 0.05f);
	XDriver = new MotorDriver(*xPivot, true);
	YDriver = new MotorDriver(*yPivot, false);

	ServoDriver *ZDriver = new ServoDriver();
	pen = new Pen(xPivot, yPivot, ZDriver);
	Task task = Task();

	//v0.0.2: Diamond
	task.Time = 500;
	task.Dest = 0.5f;
	YDriver->AddTask(task);
	task.Time = 1000;
	task.Dest = -0.5f;
	YDriver->AddTask(task);
	task.Dest = 0.5f;
	YDriver->AddTask(task);
	//Add instructions to XDriver
	task.Dest = 0.5f;
	XDriver->AddTask(task);
	task.Dest = -0.5f;
	XDriver->AddTask(task);
	task.Time = 500;
	task.Dest = 0.0f;
	XDriver->AddTask(task);

	initialized = true;
}

std::vector<Shape *> Model::getDrawables()
{
	if (initialized)
	{
		std::vector<Shape *> out = std::vector<Shape *>();
		out.push_back(yPivot);
		out.push_back(xPivot);
		out.push_back(pen);
		return out;
	}
	else
	{
		throw "Model is not initialized.";
		return std::vector<Shape *>();
	}
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