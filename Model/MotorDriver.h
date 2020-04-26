
#pragma once
#include "PivotPoint.h"
#include "Task.h"
#include "Module.h"

class MotorDriver : public Module
{

private:
	float currentPos;	 //Current position in own axis.
	float stepSize;		 //Distance for pivot movement per ms
	float timeRemaining; //Time remaining for movement
	PivotPoint *Pivot;
	bool isXDriver;

public:
	void Do(Task task);
	MotorDriver(const PivotPoint &pivot, bool IsXDriver);
	void Routine(float DeltaTime) override;

private:
	/*
	 *	Transforms next destination to step itervals
	 */
	float calculateStepSize(const Task &task);

	//TODO V delete this section V
public:
	PivotPoint &GetPivotPoint();
};

bool test_MotorDriver();

//math.h is een groot bestand, dus talla.
float abs(float val) { return (val > 0) ? val : -val; }
