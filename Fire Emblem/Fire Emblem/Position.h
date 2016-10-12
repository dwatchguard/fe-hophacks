#pragma once
#include <cmath>
class Position
{
	int x;
	int y;

public:
	Position();
	Position(int x, int y);
	bool equals(Position pos);
	int getX();
	int getY();
	int distanceFrom(Position pos);
	~Position();
};

