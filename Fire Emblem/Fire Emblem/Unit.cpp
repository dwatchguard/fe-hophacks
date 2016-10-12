#include "Unit.h"

/**
*Gets the playerId of the Unit
*
*/
int Unit::getPlayerID() { //int
	return this->playerID;
}

/**
* Move this Unit to the given Position if it is empty.
*/
void Unit::move(Position position) { //void
	if (this->moveHelper.isEmpty(position)) {
		this->moveHelper.move(this->currentPosition, position);
		this->currentPosition = position;
	}
}

/**
* Tell the Unit that it is a new turn.
*/
void Unit::refresh() { //void
	tired = false;
}
/**
* Adds a State with the given name to the Unit.
* @param state The number id representing the new State.
*/
void Unit::addState(State* state) { //void
	states.push_back(state);
}

/**
* Adds a new Skill to the Unit.
* @param skill The new Skill to add
*/
void Unit::addSkill(Skill* skill) { //void
	skills.push_back(skill);
}

void Unit::removeSkill(Skill* skill) { //void
	//TODO
}

/**
* Removes any State with the given name from the Unit.
* @param state The name of the State to remove.
*/
void Unit::removeState(State* state) { //void 
	for (int i = 0; i < this->states.size(); i++) {
		if (state->equals(this->states[i])) {
			this->states[i]->clear(this);
			this->states.erase(states.begin() + i--);
		}
	}
}


/**
* This Unit's equipped weapon
* @name Unit#equippedWeapon
* @type Weapon
* @readonly
*/
Weapon Unit::getEquippedWeapon() {
	if (this->canWield(this->items[0]) && hasWeaponEquipped) {
		return equippedWeapon;
	}
	return NULL;

}

/**
* This Unit's damage
* @name Unit#damage
* @type Damage
* @readonly
*/
Damage* Unit::getAttackDamage() {
	if (!hasWeaponEquipped) {
		return NULL;
	}
	Damage* damage;
		if (equippedWeapon.isPhysical()) { //Calculate damage to deal.
			damage = new Damage(this, this->equippedWeapon.getDamage() +this->stats[ATTACK], PHYSICAL, 1);
		}
		else {
			damage = new Damage(this, this->equippedWeapon.getDamage() + this->stats[MAGIC], MAGICAL, 1);
		}
		return damage;
}

/**
* Attempt to strike the opposing Unit once.
* @param enemyUnit the enemy Unit to attack
*/
void Unit::engage(Unit* enemyUnit) {
	//this->updateStates("onEngageStart");//this should be an event
	//enemyUnit.updateStates("onEngagedStart");//this should be an event
	int randHit;
	int randCrit;
	randHit = rand() % 100;
	randCrit = rand() % 100;
	Weapon equippedWeapon = this->equippedWeapon;
	int hit = this->getAccuracy() - enemyUnit->getAvoid();
	Damage* damage = this->getAttackDamage();
	/*
	if (damage.value === 0) {
	return; // we can't attack
	}
	*/

	if (randHit < hit) { //We hit the enemy
		equippedWeapon.use(this);
		//weaponStatus.isBroken = equippedWeapon.uses <= 0; Our weapons don't break

		//TODO Add an on-hit event
		/*TODO add crit WESTY CAN DO THIS I DONT UNDERSTAND HIS GOSH DARNED FORMULA
		if (randCrit < crit) {
			damage.originalValue = damage.value;
			damage.value = damage.value * this->critDamage;
			damage.isCritical = true;
		}
		*/
		enemyUnit->takeDamage(damage);
	}
	//Event here 
	//this->updateStates("onEngageEnd");
	//enemyUnit.updateStates("onEngagedEnd", enemyUnit);
}

/**
* Attempt a battle against an opposing Unit
* @param enemyUnit The Unit to attack
*/
void Unit::attackUnit(Unit* enemyUnit) { //void

	Unit* aggresor = this;
	Unit* target = enemyUnit;
	Weapon enemyWeapon = target->equippedWeapon;
	int distance = aggresor->currentPosition.distanceFrom(target->currentPosition);
	bool attackBackable = (&enemyWeapon != NULL) &&
		enemyUnit->canWield(&enemyWeapon) &&
		enemyWeapon.minRange <= distance &&
		enemyWeapon.maxRange >= distance;

	//this->updateStates("onAttackStart", attackData); EVENTS
	//enemyUnit.updateStates("onAttackedStart", attackData);

	aggresor->engage(target); //Attack the enemy
	if (target->hp == 0) { //If they died, it is over; //TODO add an event for ending the battle and killing
									 //this->updateStates("onAttackEnd", attackData);
									 //enemyUnit.updateStates("onAttackedEnd", attackData);
		return;
	}

	if (attackBackable) {

		target->engage(aggresor); //Get attacked in return
		if (aggresor->hp == 0) { //If we died, it is over;
										   //this->updateStates("onAttackEnd", attackData);
										   //enemyUnit.updateStates("onAttackedEnd", attackData);
			return;
		}
	}
	if (aggresor->stats[SPEED] > target->stats[SPEED] +4) { //If we are fast, then we attack again

		aggresor->engage(target);

		if (target->hp == 0) { //If they died, it is over;
										 //this->updateStates("onAttackEnd", attackData);
										 //enemyUnit.updateStates("onAttackedEnd", attackData);
			return;
		}
	}
	else if (aggresor->stats[SPEED] +4 < target->stats[SPEED] && attackBackable) { //If they are fast, then have them attack again

		target->engage(aggresor); //Get attacked in return
	}
	//this->updateStates("onAttackEnd", attackData);
	//enemyUnit.updateStates("onAttackedEnd", attackData);
}

/**
* Have us take the appropriate damage.
* @param damage, an object with a damage type and damage to take.
*/
void Unit::takeDamage(Damage* damage) { //void
									   //this->updateStates("onTakeDamage", damage);
	int value = damage->getValue();
	if (damage->getType() == PHYSICAL) {
		value -= this->stats[DEFENSE];
	}
	else if (damage->getType() == MAGICAL) {
		value -= this->stats[RESISTANCE];
	}
	value *= damage->getMultiplier();
	if (value < 0) { //we don't heal enemies with high resistances when we hit them
		value = 0;
	}
	this->hp -= value;
	if (this->hp <= 0) {
		this->hp = 0;
		this->die();
	}
	//this->updateStates("onTookDamage", damage);
};

/**
* Heals the unit by the designated (positive) amount.
* @amount amount to heal the Unit. Value of "all" will fully heal the Unit
*/
void Unit::heal(int amount) {
	if (amount > 0) {
		this->hp += amount;
	}
	if (this->hp > this->maxHP) {
		this->hp = this->maxHP;
	}
}

/**
* This Unit's accuracy
* @name Unit#accuracy
* @type int
* @readonly
*/
int Unit::getAccuracy() {
	if (!hasWeaponEquipped) {
		return 0;
	}
	return this->equippedWeapon.hit + 2 * (this->stats[SKILL]) + this->stats[SPEED];

}

/**
* This Unit's avoid
* @name Unit#avoid
* @type int
* @readonly
*/
int Unit::getAvoid() {
	return 2 * this->stats[SPEED] + this->stats[SKILL];
}

/**
* TODO
*/
bool Unit::canWield(Item* item) {
	if (item == NULL || !item->isWeapon()) {
		return false;
	}
	Weapon weapon = *((Weapon*)item);
	for (int i = 0; i <weaponTypes.size(); i++) {
		if (this->weaponTypes[i] == weapon.getType()) {
			return true;
		}
	}
	return false;
};

/** Equip the Weapon in the desired Inventory slot
* @param index the inventory slot to equip
*/
void Unit::equip(int index) {
	if (index > 0 && index < this->items.capacity()) {
		Item* temp = this->items[0];
		this->items[0] = this->items[index];
		this->items[index] = temp;
	}
}

/** Use the Item in the desired Inventory slot
* @param index the inventory slot to use
*/
void Unit::useItem(int index) {
	if (index > -1 && index < this->items.size()) {
		this->items[index]->use(this);
	}
}

/**
* This Unit's position
* @name Unit#position
* @type Position
* @readonly
*/
Position Unit::getPosition() {
	return this->currentPosition;
}
void Unit::setPosition(Position pos) {
	this->currentPosition = pos;
}
/**
* This Unit's last position
* @name Unit#lastPosition
* @type Position
* @readonly
*/
Position Unit::getLastPosition() {
	return this->lastPosition;
}

void Unit::setLastPosition(Position pos) {
	this->lastPosition = pos;
}

/**
* This Unit's name
* @name Unit#name
* @type string
* @readonly
*/
std::string Unit::getName() {
	return this->name;
}


/**
* This Unit's hp
* @name Unit#hp
* @type int
* @readonly
*/
int Unit::getHP() {
	return this->hp;
}


/**
* This Unit's maxHP
* @name Unit#maxHP
* @type int
* @readonly
*/
int Unit::getMaxHP() {
	return this->maxHP;
}


/**
* This Unit's attack
* @name Unit#attack
* @type int
* @readonly
*/
int Unit::getAttack() {
	return (this->stats[ATTACK] + this->bonusStats[ATTACK]) * this->statMultipliers[ATTACK];
}

/**
* This Unit's defense
* @name Unit#defense
* @type int
* @readonly
*/
int Unit::getDefense() {
	return (this->stats[DEFENSE] + this->bonusStats[DEFENSE]) * this->statMultipliers[DEFENSE];
}

/**
* This Unit's resistance
* @name Unit#resistance
* @type int
* @readonly
*/
int Unit::getResistance() {
	return (this->stats[RESISTANCE] + this->bonusStats[RESISTANCE]) * this->statMultipliers[RESISTANCE];
}

/**
* This Unit's magic
* @name Unit#magic
* @type int
* @readonly
*/
int Unit::getMagic() {
	return (this->stats[MAGIC] + this->bonusStats[MAGIC]) * this->statMultipliers[MAGIC];
}


/**
* This Unit's speed
* @name Unit#speed
* @type int
* @readonly
*/
int Unit::getSpeed() {
	return (this->stats[SPEED] + this->bonusStats[SPEED]) * this->statMultipliers[SPEED];
}


/**
* This Unit's skill
* @name Unit#skill
* @type int
* @readonly
*/
int Unit::getSkill() {
	return (this->stats[SKILL] + this->bonusStats[SKILL]) * this->statMultipliers[SKILL];
}

int Unit::getCharisma() {
	return (this->stats[CHARISMA] + this->bonusStats[CHARISMA]) * this->statMultipliers[CHARISMA];
}

int Unit::getConstitution() {
	return (this->stats[CONSTITUTION] + this->bonusStats[CONSTITUTION]) * this->statMultipliers[CONSTITUTION];
}

/**
* This Unit's movement
* @name Unit#movement
* @type int
* @readonly
*/
int Unit::getMovement() {
	return this->movement;
}


/**
* This Unit's playerID
* @name Unit#playerID
* @type int
* @readonly
*/
int Unit::getplayerID() {
	return this->playerID;

}

/**
* This Unit's skills
* @name Unit#skills
* @type Skill[]
* @readonly
*/
std::vector<Skill*> Unit::getSkills() {
	return this->skills;
}

/**
* This Unit's states
* @name Unit#states
* @type State[]
* @readonly
*/
std::vector<State*> Unit::getStates() {
	return this->states;
}

/**
* This Unit's items
* @name Unit#items
* @type Item[]
* @readonly
*/
std::vector<Item*> Unit::getItems() {
	return this->items;
}

/**
* This Unit's stats
* @name Unit#stats
* @type int[]
* @readonly
*/
std::vector<int> Unit::getStats() {
	return stats;
}


/**
* This Unit's flying status
* @name Unit#canFly
* @type bool
* @readonly
*/
bool Unit::canFly() {
    return this->flying;
}

/**
* Called when a unit is dies. Sets the Units state to dead
*/
void Unit::die() {
	this->dead = true;
	skillContext->killUnitAtPosition(this->currentPosition);
}

/**
* This Unit's ranges it can attack
* @name Unit#ranges
* @type int[]
* @readonly
*/
std::vector<int> Unit::getRanges() { //can have duplicates... for now. I'm lazy
	std::vector<int> ranges;
	for (int i = 0; i <this->items.size; i++) {
		if (this->canWield(this->items[i])) {
			Weapon weapon = *((Weapon*)&items[i]); //this is disgusting typecasting pls send help
			for (int k = weapon.minRange; k <= weapon.maxRange; k++) {
				ranges.push_back(k);
			}
		}
	}
	return ranges;
}

/**
* This Unit's ranges it can attack with its equipped weapon
* @name Unit#equippedRanges
* @type int[]
* @readonly
*/
std::vector<int> Unit::getEquipedRanges() {
	std::vector<int> ranges;
	for (int k = this->equippedWeapon.minRange; k <= this->equippedWeapon.maxRange; k++) {
		ranges.push_back(k);
	}
	return ranges;
}

/**
* This Unit's SkillContext
* @name Unit#skillContext
* @type SkillContext
* @readonly
*/
SkillContext* Unit::getSkillContext() {
	return skillContext;
}
void Unit::setSkillContext(SkillContext* context) {
	skillContext = context;
}
