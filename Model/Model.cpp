#include "Model.h"

Model::Model()
	: XDriver(nullptr), YDriver(nullptr), pen(nullptr) {}

Model::~Model()
{
	delete XDriver, YDriver, pen;
}

std::vector<Module *> Model::getDynamicObjects()
{
	std::vector<Module *> out;
	out.push_back(XDriver);
	out.push_back(YDriver);
	return out;
}

void Model::Init()
{
	/*Ik hou er niet van om alles tussen de -1 en 1
		te doen. We kunnen het ook op een andere
		schaal doen, maar dan moeten we een
		transformatie functie toevoegen in View
	*/
	Square xPivot({-0.55f, 0.5f}, 0.05f);
	Square yPivot({-0.5f, 0.45f}, 0.05f);
	XDriver = new MotorDriver(xPivot, true);
	YDriver = new MotorDriver(yPivot, false);
	//TODO initializeer pen

	//Als laatste! Timer begint na initializatie.
	timer = new Time();
}
