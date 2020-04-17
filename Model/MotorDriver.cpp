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

bool test_MotorDriver()
{
	//TODO - implimenteer MotorDriver Test
}