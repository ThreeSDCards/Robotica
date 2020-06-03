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
		std::vector<Dynamic *> out = std::vector<Dynamic *>();
		out.push_back(XDriver);
		out.push_back(YDriver);
		out.push_back(pen);
		out.push_back(servo);
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

	servo = new ServoDriver();
	pen = new Pen(xPivot, yPivot, servo);

	//v0.0.3: Curves!
	auto Circle = DrawCircle(0.3f, 3000.0f, {0.5f,-0.3f});
	XDriver->AddTask(Circle.X);
	YDriver->AddTask(Circle.Y);
	servo->AddTask(Circle.Z);/*
	auto Circle2 = DrawCircle(0.3f, 3000.0f, {0.5f, -0.3f});
	XDriver->AddTask(Circle2.X);
	YDriver->AddTask(Circle2.Y);
	servo->AddTask(Circle2.Z);*/

	initialized = true;
}

TaskSet Model::DrawCircle(float radius, float time, Point2 pos) {
	TaskSet out;
	Task task;

	//Go to position
	task.Time = POINTTIME;
	task.Dest = pos.X;
	out.X.push(task);
	task.Dest = pos.Y;
	out.Y.push(task);

	//Go to right side of circle
	task.Time = RADIUSTIME;
	task.Dest = pos.X + radius;
	out.X.push(task);
	task.Dest = pos.Y;
	out.Y.push(task);

	//Handle Z
	task.Time = POINTTIME + RADIUSTIME;
	task.Dest = 1;
	out.Z.push(task);
	//????????????????????????????????????????????????
	task.Time = time + POINTTIME + RADIUSTIME * 1.82f;
	//????????????????????????????????????????????????
	task.Dest = -1;
	out.Z.push(task);

	
	//Divide time over segments;
	task.Time = time / CIRCLEDEF;

	for (int i = 0; i < CIRCLEDEF; i++) {
		auto theta = (2 * M_PI) / CIRCLEDEF * i;
		task.Dest = float(cos(theta) * radius + pos.X);
		out.X.push(task);
		task.Dest = float(sin(theta) * radius + pos.Y);
		out.Y.push(task);
	}

	//Go back to pos
	task.Time = RADIUSTIME;
	task.Dest = pos.X;
	out.X.push(task);
	task.Dest = pos.Y;
	out.Y.push(task);

	return out; 
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
	catch (const char* e)
	{
		printf("%s\n", e);
		return false;
	}
	return true;
}
