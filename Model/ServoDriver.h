#pragma once
class ServoDriver
{

private:
	bool up = false;

public:
	ServoDriver() : up(false){};
	void Toggle();

	bool IsUp();
};

bool test_ServoDriver();
