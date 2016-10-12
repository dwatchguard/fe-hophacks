#pragma once
#include "Unit.h"
class State
{
	int stateID;
public:
	virtual void clear(Unit* unit) = 0;
	bool equals(State* state);
};

