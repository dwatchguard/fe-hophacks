#pragma once
#include "Item.h"
class Weapon : public Item
{
public:
	static void InitializeWeapons();
	static std::vector<Weapon>* weapons;
	std::string name;
	int type;
	int mt;
	int hit;
	int crit;
	int minRange;
	int maxRange;
	bool IsPhysical;
	Skill* skill;
public:
	Weapon(int weaponID);
	Weapon(int Type, int MT, int Hit, int Crit, int MinRange, int MaxRange, bool IsPhysical, Skill* Skill);
	bool isWeapon();
	void use(Unit *unit);
	void use();
	int getType();
	std::string getName();
	int getDamage();
	int getMinRange();
	int getMaxRange();
	int getAccuracy();
	bool isPhysical();
	void equipTo(Unit *unit);
	void unequipFrom(Unit *unit);
};

