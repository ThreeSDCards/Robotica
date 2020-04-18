#include "ServoDriver.h"

void ServoDriver::Toggle()
{
	up ^= 1;
}

bool ServoDriver::IsUp()
{
	return up;
}

bool test_ServoDriver()
{
	try
	{
		ServoDriver &sd = *(new ServoDriver());

		//Test IsUp
		if (sd.IsUp())
			throw "SERVODRIVER ERROR (ISUP)";

		//Test Toggle
		sd.Toggle();
		if (!sd.IsUp())
			throw "SERVODRIVER ERROR (TOGGLE)";

		return true;
	}
	catch (const char *e)
	{
		return false;
	}
}