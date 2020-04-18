#pragma once
class Point
{

public:
	float X;
	float Y;

	Point(){};
	Point(float x, float y);

	Point Add(float x, float y);
};

bool test_Point();
