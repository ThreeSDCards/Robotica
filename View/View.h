#pragma once
#include "../Model/Drawable.h"
#include "../Model/Model.h"

class View : public Drawable
{
private:
	Model *model;

public:
	View(Model *model);
	void Update();
};
