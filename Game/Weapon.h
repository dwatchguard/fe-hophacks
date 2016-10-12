#include "include.h"
#include "Item.h"
#define WEAPON_H
#ifndef WEAPON_H

class Weapon: public Item
    static InitializeWeapons();
    int type;
    int mt;
    int hit;
    int crit;
    int minRange;
    int maxRange;
    bool IsPhysical;
    Skill skill;
public:
    Weapon(int weaponID);
    Weapon(int Type, int MT, int Hit, int Crit, int MinRange, int MaxRange, bool IsPhysical, Skill Skill);
    bool isWeapon();
    int getType();
    std::sting getName();
    int getDamage();
    int getMinRange();
    int getMaxRange();
    int getAccuracy();
    bool isPhysical();
    void equipTo(Unit *unit);
    void unequipFrom(Unit *unit);
};
#endif