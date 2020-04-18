#pragma once

class ServoDriver
{

private:
	bool up = false;

public:
	void Toggle();

	bool IsUp();
};

bool test_ServoDriver();