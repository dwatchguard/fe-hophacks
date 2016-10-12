#include "stdafx.h"
#include "Skill.h"

bool Skill::isValidTarget(Position pos) {
	std::vector<Position> targets = this->targetPositions();
	for (int i = 0; i < targets.size(); i++) {
		if (targets[i].equals(pos)) {
			return true;
		}
	}
	return false;
};
bool Skill::isReady() {
	return cooldown >= 0;
};
void Skill::setContext(SkillContext *context) {
	context = &context;
};
