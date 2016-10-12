#include "stdafx.h"
#include "Position.h"


Position::Position(int x, int y) {
	this->x = x;
	this->y = y;
}


Position::~Position()
{
}

bool Position::equals(Position pos) {
	return this->x == pos.x && this->y == pos.y;
}

int Position::distanceFrom(Position pos) {
	return std::abs(this->x - pos.x) + std::abs(this->y - pos.y);
}