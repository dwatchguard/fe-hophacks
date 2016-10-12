#include "include.h"
#ifndef Skill_H
#define Skill_H
#define NUMSKILLS 1;
#define PASSIVE 0
#define ACTIVE_WAIT 1
#define Active_CHAINABLE 2

class Skill {
    protected:
    int cooldown;
    int skillType;
    Unit owner;
    bool isTargeted;
    static SkillContext context;
    public:
    virtual bool isReady();
    virtual void activate() = 0;
    virtual bool isValidTarget(Position pos);
    virtual std::Vector<Position> targetPositions() = 0;
    void setContext(Skillcontext &context);
    
};
#endif