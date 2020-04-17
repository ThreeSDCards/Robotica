#include "ServoDriver.h"

void ServoDriver::Toggle()
{
	up ^= 1;
}

bool ServoDriver::IsUp()
{
	return up;
}
