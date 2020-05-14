#pragma once
#include "../Model/Drawable.h"
#include "../Model/Model.h"
#include "../Model/Time.h"
#include <vector>

class View : public Drawable
{
private:
	Model *model;
	Time t;

public:
	View(Model *model);
	void Update();
	void Draw() override;
};
