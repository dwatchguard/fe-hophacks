#ifndef STEADYAIM_H
#define STEADYAIM_H
class SteadyAim :  public Skill {
    cooldown = -1;
    skillType = PASSIVE;
    isTargeted = false;
    public:
    SteadyAim::SteadyAim(Unit owner);
}

#endif