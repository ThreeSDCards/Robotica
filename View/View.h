#pragma once
#include "../Model/Drawable.h"
#include "../Model/Model.h"
#include "../Model/Time.h"
#include <vector>
#include <iostream>

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

bool test_View();