#ifndef PEN_H
#define PEN_H

class Pen : Square {

private:
	PivotPoint* PivotX,_PivotY;
	ServoDriver* servo;
};

#endif
