#pragma once
#include "Dynamic.h"

class Module : public Dynamic
{

private:
	bool EN;
	bool RDY;

public:
	void Enable();

	void Disable();

	bool Enabled();

	bool IsReady();

protected:
	void SetReady(bool stat);
};