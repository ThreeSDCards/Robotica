#pragma once

class Model
{

public:
	ServoDriver servoDriver;
	MainController mainController;
	std::vector<MotorDriver> DriverX, _DriverY;

private:
	std::vector<PivotPoint> PivotX, _PivotY;

public:
	Pen pen;
};