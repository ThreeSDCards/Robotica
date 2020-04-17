#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

class MotorDriver : public Module {

private:
	float currentPos;
	float speed;
	float timeRemaining;
	PivotPoint* Pivot;
	bool isXDriver;

public:
	void Do(Task& task);

	float calculateDeltaS(Task% task);
};

#endif
