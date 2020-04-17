#ifndef SERVODRIVER_H
#define SERVODRIVER_H

class ServoDriver
{

private:
	bool up;

public:
	void Toggle();

	bool IsUp();
};

#endif
//TODO ServoDriver test