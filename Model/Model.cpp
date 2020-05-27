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
	xPivot = new Square({ -0.5f, 0.5f }, 0.05f);
	yPivot = new Square({ -0.5f, 0.5f }, 0.05f);
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
	task.Dest = -0.5f;
	XDriver->AddTask(task);
	task.Dest = 0;
	XDriver->AddTask(task);
	task.Dest = 0.5;
	XDriver->AddTask(task);

	//Y
	task.Time = 1000;
	task.Dest = 0.5f;
	YDriver->AddTask(task); //Wait for X to get in position
	YDriver->AddTask(MakeCurve(5, 1000, 0.5, 0.5, false,false));
	YDriver->AddTask(MakeCurve(5, 1000, 0.5, 0.5, true,false));
	YDriver->AddTask(MakeCurve(5, 1000, 0.5, 0.5, true, true));
	//YDriver->AddTask(MakeCurve(5, 1000, 0.5, 0.5, false, true));

	//Z
	task.Time = 1000;
	servo->AddTask(task);


	initialized = true;
}

std::queue<Task> Model::MakeCurve(int def, float time, float XLength, float YLength, bool invertY, bool invertX) {
	std::queue<Task> out = std::queue<Task>();
	float timeChunk = time / def;
	float XChunk = XLength / def;
	Task task = Task();
	task.Time = timeChunk;
	for (int i = 0; i < def; i++) {
		if (!invertY && !invertX) {
			task.Dest = 1 - sin(acos(((i + 1) * XChunk) / XLength));
			task.Dest *= YLength;
			task.Dest = 1 - task.Dest;
			task.Dest -= 0.5;
			out.push(task);
		}
		else if(invertY && !invertX) {
			task.Dest = 1 - sin(acos(((def - i - 1) * XChunk) / XLength));
			task.Dest *= YLength;
			task.Dest -= 0.5;
			out.push(task);
		}
		else if (invertY && invertX) {
			task.Dest = 1 - sin(acos(((def - i -1) * !XChunk) / XLength));
			task.Dest *= YLength;
			task.Dest -= 0.5;
			out.push(task);
		}
	}
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
