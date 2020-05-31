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
	Task task = Task();

	//v0.0.3: Curves!
	//X
	task.Time = 1000;
	task.Dest = 0;
	XDriver->AddTask(task);
	servo->AddTask(task);
	//Y
	task.Dest = 0;
	YDriver->AddTask(task);

	auto Circle = DrawCircle(0.3f, 3000.0f);
	XDriver->AddTask(Circle.X);
	YDriver->AddTask(Circle.Y);
	servo->AddTask(Circle.Z);

	initialized = true;
}

TaskSet Model::DrawCircle(float radius, float time) {
	TaskSet out;
	Task task;
	//Get starting point
	Point start;
	start.X = XDriver->LastPos();
	start.Y = YDriver->LastPos();

	//Divide time over segments plus travel to top and back to center.
	task.Time = time / (CIRCLEDEF + 2);
	
	//Go to right side of circle
	task.Dest = XDriver->LastPos() + radius;
	out.X.push(task);

	for (int i = 0; i < CIRCLEDEF; i++) {
		auto theta = (2 * M_PI) / CIRCLEDEF * i;
		//Calculate new X
		task.Dest = float(cos(theta));
		//Multiply by size
		task.Dest *= radius;
		out.X.push(task);

		task.Dest = float(sin(theta));
		task.Dest += float(start.Y);
		out.Y.push(task);
	}

	task.Dest = start.X;
	out.X.push(task);
	task.Dest = start.Y;
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