#include "stdafx.h"
#include "State.h"


bool State::equals(State* state) {
	return stateID == state->stateID;
}
