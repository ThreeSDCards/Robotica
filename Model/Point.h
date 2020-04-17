#ifndef POINT_H
#define POINT_H

class Point
{

public:
	float X;
	float Y;

	Point(){};
	Point(float x, float y);

	Point Add(float x, float y);
};

#endif
//TODO Point test