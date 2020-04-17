#ifndef MODEL_H
#define MODEL_H

class Model {

public:
	ServoDriver servoDriver;
	MainController mainController;
	std::vector<MotorDriver> DriverX,_DriverY;
private:
	std::vector<PivotPoint> PivotX,_PivotY;
public:
	Pen pen;
};

#endif
