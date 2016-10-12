#pragma once
#include "Unit.h"

#define PHYSICAL 0
#define MAGICAL 1
#define TRUE 2

class Damage
{
	int value;
	float multiplier;
	int type;
	Unit *owner;
public:
	Damage(Unit *owner, int value, int type, float multiplier);
	int getValue();
	int getType();
	float getMultiplier();
	~Damage();
};

