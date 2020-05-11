
#pragma once
#include "Module.h"
#include "Square.h"

struct Task
{
	float Time; //Amount of seconds to execute task
	float Dest; //Floating point position of destination
};

class MotorDriver : public Module
{

private:
	float currentPos;	 //Current position in own axis.
	float stepSize;		 //Distance for pivot movement per ms
	float timeRemaining; //Time remaining for movement
	Shape *Pivot;
	bool isXDriver;

public:
	void Do(Task task);
	MotorDriver(Shape &pivot, bool IsXDriver);
	void Routine(float DeltaTime) override;

private:
	/*
	 *	Transforms next destination to step itervals
	 */
	float calculateStepSize(const Task &task);

	//This friend function is only used for testing :)
	friend Shape &____GetPivotPoint(const MotorDriver &);
};

Shape &____GetPivotPoint(const MotorDriver &driver);

bool test_MotorDriver();
bool test_Module();
