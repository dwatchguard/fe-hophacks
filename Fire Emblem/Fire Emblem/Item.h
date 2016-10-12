#pragma once
#include "Unit.h"
class Item 
{
public:
	virtual bool isWeapon() = 0;
	virtual void use(Unit *Unit) = 0;
};

