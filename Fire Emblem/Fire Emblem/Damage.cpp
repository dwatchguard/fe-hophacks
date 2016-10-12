#include "stdafx.h"
#include "Damage.h"


Damage::Damage(Unit *owner, int value, int type, float multiplier)
{
	this->owner = owner;
	this->value = value;
	this->type = type;
	this->multiplier = multiplier;
}


Damage::~Damage()
{
}

int Damage::getValue() {
	return value;
}
int Damage::getType() {
	return type;
}
float Damage::getMultiplier() {
	return multiplier;
}