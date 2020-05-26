#include "MotorDriver.h"

MotorDriver::MotorDriver(Shape &pivot, bool isX)
	: Pivot(&pivot), isXDriver(isX) {
	SetReady(true);
}

void MotorDriver::DoTask(Task task)
{
	//Set member fields
	stepSize = calculateStepSize(task);
	timeRemaining = task.Time;
	dest = task.Dest;
	//Ready = false
	Module::SetReady(false);
}

float MotorDriver::calculateStepSize(const Task &task)
{
	//Get current pos
	float pos = (isXDriver) ? Pivot->GetOrig().X : Pivot->GetOrig().Y;
	//Find difference in position
	float deltaS = task.Dest - pos;
	// Divide difference over remaining timespan in ms
	return deltaS / task.Time;
}

void MotorDriver::Routine(float DeltaTime)
{
	//Execute current task
	if (!IsReady())
	{
		//Calculate step size
		auto Step = stepSize * DeltaTime;
		//Update pivot pos
		if (isXDriver) {
			Pivot->Move(Step, 0);
		}
		else
			Pivot->Move(0, Step);

		//Update internal variables
		timeRemaining -= DeltaTime;

		std::cout << "X: " << Pivot->GetOrig().X << " Y: " << Pivot->GetOrig().Y << "\n";

		//Check if finished with task.
		if (timeRemaining <= 0) {
			//Set pos to exact dest (Floating point isn't perfect.)
			Point pos = Pivot->GetOrig();
			isXDriver ? pos.X : pos.Y = dest;
			Pivot->SetOrig(pos);

			SetReady(true);
		}
	}
	//Check if there are any tasks in queue
	if (IsReady() && !ToDo.empty()) {

		DoTask(ToDo.front());
		ToDo.pop();
	}
}

Shape &____GetPivotPoint(const MotorDriver &driver)
{
	return *driver.Pivot;
}

void MotorDriver::AddTask(Task task) {
	ToDo.push(task);
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
		task.Time = 1000; //timeRemaining wordt hierdoor 1000ms

		Driver.AddTask(task);
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
		xdriver.AddTask(task);

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
