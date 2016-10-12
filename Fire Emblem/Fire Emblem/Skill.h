#pragma once
#include "Unit.h"
class Skill {
protected:
	int cooldown;
	int skillType;
	Unit* owner;
	bool isTargeted;
	static SkillContext* context;
public:
	virtual bool isReady();
	virtual void activate() = 0;
	virtual bool isValidTarget(Position pos);
	virtual std::vector<Position> targetPositions() = 0;
	static void setContext(Skillcontext *context);

};
