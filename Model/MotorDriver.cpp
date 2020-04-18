#include "MotorDriver.h"

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
	float deltaS = abs(currentPos - task.Dest);
	// Divide difference over remaining timespan in ms
	return deltaS / (task.Time * 1000);
}

void MotorDriver::Routine()
{
	//TODO - Impliment MotorDriver::Routine
}

bool test_MotorDriver()
{
	//TODO - implimenteer MotorDriver Test
	try
	{
		PivotPoint &pv = *(new PivotPoint({0, 0}));
		MotorDriver &md = *(new MotorDriver(pv, true));
	
	}
	catch (const char *e)
	{
	}
}