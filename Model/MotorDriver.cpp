#include "MotorDriver.h"

MotorDriver::MotorDriver(Shape &pivot, bool isX)
	: Pivot(&pivot), isXDriver(isX) {}

void MotorDriver::Do(Task task)
{
	//Set member fields
	stepSize = calculateStepSize(task);
	timeRemaining = task.Time;
	//Ready = false
	Module::SetReady(false);
}

float MotorDriver::calculateStepSize(const Task &task)
{
	//Find difference in position
	float deltaS = task.Dest - currentPos;
	// Divide difference over remaining timespan in ms
	return deltaS / (task.Time * 1000);
}

void MotorDriver::Routine(float DeltaTime)
{
	if (!IsReady())
	{
		//Calculate step size
		auto Step = stepSize * DeltaTime;
		//Update pivot pos
		if (isXDriver)
			Pivot->Move(Step, 0);
		else
			Pivot->Move(0, Step);

		//Update internal variables
		currentPos += Step;
		timeRemaining -= DeltaTime;

		//Check if finished with task.
		if (timeRemaining <= 0)
			SetReady(true);
	}
}

Shape &____GetPivotPoint(const MotorDriver &driver)
{
	return *driver.Pivot;
}

//TESTS
bool test_Module()
{
	try
	{
		//Init prerequisites
		auto pv = Square({0, 0}, 0.0f);
		auto Driver = MotorDriver(pv, false);

		//Test Disable
		Driver.Disable();
		if (Driver.Enabled())
			throw "MODULE ERROR (DISABLE)";

		//Test Enable
		Driver.Enable();
		if (!Driver.Enabled())
			throw "MDOULE ERROR (ENABLE)";

		//Test Ready
		Task task;
		task.Dest = 1;
		task.Time = 1;

		Driver.Do(task);
		Driver.Routine(500.0f);
		if (Driver.IsReady())
			throw "MODULE ERROR (READY)";

		Driver.Routine(501.0f);
		if (!Driver.IsReady())
			throw "MODULE ERROR (READY)";
	}
	catch (const char *e)
	{
		return false;
	}
	return true;
}

bool test_MotorDriver()
{
	try
	{
		//Initialize prerequisites.
		auto &pv = *(new Square({0, 0}, 0.0f));
		//Initialize drivers
		auto xdriver = MotorDriver(pv, true);
		auto ydriver = MotorDriver(pv, false);

		//Set task
		auto task = Task();
		task.Time = 1; //1s
		task.Dest = 1; //(1,0)

		//Execute task
		xdriver.Do(task);

		//Wait half a second
		xdriver.Routine(500.0f);

		//Test predicted location (0.5, 0)
		if (____GetPivotPoint(xdriver).GetOrig().X != 0.5f)
			throw "MOTORDRIVER ERROR";
	}
	catch (const char *e)
	{
		return false;
	}
	return true;
}