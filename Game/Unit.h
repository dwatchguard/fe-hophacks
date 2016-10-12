#include "include.h"
#include "Unit.h"

#ifndef UNIT_H
#define UNIT_H

class Unit {

bool die(); 

virtual 
Unit(std::vector<int> stats, std::vector<int>, growths, std::vector<int> items, std::sting name, std::vector<int> skills, int id, int level, int unitClass, SkillContext *skillContext);
int getPlayerID();
void move(Position position);
void refresh();
void updateStates(when, argument);
void addState(int state);
void addSkill(Skill skill);
void removeState(int state);
Weapon getEquippedWeapon();
Damage getAttackDamage();
void engage(Unit enemyUnit);
void attackUnit(Unit enemyUnit);
void takeDamage(Damage damage);
void heal(int amount);
int getAccuracy();
int getAvoid();
bool canWield(Item item);
void equip(int index); 
void useItem(int index);
Position getPosition();
void setPosition(Position pos);
Position getLastPosition();
void setLastPosition(Position pos);
std::string getName();
int getHP();
int getMaxHP();
int getAttack();
int getDefense();
int getResistance();
int getMagic(); 
int getSpeed();
int getSkill(); 
int getCharisma();
int getConstitution(); 
int getMovement();
int getplayerID();
std::vector<Skill> getSkills();
std::vector<State> getStates();
std::vector<Item> getItems();
std::vector<Skill> getStats();
bool canFly();
std::vector<int> getRanges();
std::vector<int> getEquipedRanges();
SkillContext* getSkillCOntext();
};


#endif
