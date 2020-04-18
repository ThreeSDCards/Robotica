#pragma once

class Task
{

public:
	float Time; //Amount of seconds to execute task
	float Dest; //Floating point position of destination
};

bool test_Task()
{
	try
	{
		Task task({1.0f, 1.0f});
		task.Time += 5.0f;
		task.Dest -= 0.3f;
		if (task.Time != 6.0f || task.Dest != 0.7f)
			throw "TASK ERROR";
		return true;
	}
	catch (const char *e)
	{
		return false;
	}
};