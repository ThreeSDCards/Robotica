#ifndef MODULE_H
#define MODULE_H

class Module
{

private:
	bool EN;
	bool RDY;

public:
	void Enable();

	void Disable();

	bool Enabled();

	bool IsReady();

	/**
	 * Loop routine of module.
	 */
	virtual void Routine() = 0;

	void SetReady(bool stat);
};

#endif
