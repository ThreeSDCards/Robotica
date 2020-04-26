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
	float deltaS = task.Dest - currentPos;
	// Divide difference over remaining timespan in ms
	return deltaS / (task.Time * 1000);
}

void MotorDriver::Routine(float DeltaTime)
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
}
