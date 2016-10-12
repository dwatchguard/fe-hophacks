#include "Skill.h"

    bool Skill::isValidTarget(Position pos) {
        std::vector<Position> targets = this->targetPositions();
        if (targets == NULL) {
            return false;
        }
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
    void setContext(SkillContext &context) {
        this->context = &context;
    };