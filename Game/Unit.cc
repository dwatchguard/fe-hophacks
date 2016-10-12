#include "Unit.h"


/**
 * Represents a Unit in the game.
 * @constructor
 * @param unitData The unit's data.
 * @param id The Unit's team's ID number,
 */
Unit::Unit(std::vector<int> stats, std::vector<int>, growths, std::vector<int> items, std::sting name, std::vector<int> skills, int id, int level, int unitClass, SkillContext *skillContext) {
    srand (time(NULL));
    this->name = name;
    this->dead = false;
    this->currentPosition = new Position(0, 0);
    this->lastPosition = new Position(0, 0);
    this->weaponTypes = undefined;
    this->classType = undefined;
    this->airTraversable = false;
    this->playerID = id;
    this->skillContext = skillContext;
    this->stats = stats;
    this->bonusStats = new std::vector<int>();
    this->statMultipliers = new std::vector<int>(1, NUMATRRIBUTES);
    this->equipped = true;

    this->skills = new std::vector<Skill>();
    this->states = new std::vector<State>(); //Array of all of our states
    this->items = new std::vector<Item>(); //Array of all of our items, the first Item is equppied if possible. If not, then no Item is equipped. *DUAL BLADES ARE AN EXCEPTION*

    for (var i = 0; i < skills.size(); i++) {
        if (skills[i] >= 0 && skills[i] < NUMSKILLS) {
            this->skills[i] = new Skill(skills[i], this);
        }
    }
    
    
    
    
    for (i = 0; i < unitData.items.length; i++) {
        if (unitData.items[i] !== '' && staticItems[unitData.items[
                i]] !== undefined) {
            this->_items[i] = staticItems[unitData.items[i]]();
        }
    }
    //this->_skills[4] = staticSkills.WAIT(this)
    //this->_skills[5] = staticSkills.ATTACK(this)

}

/**
 *Gets the playerId of the Unit
 *
 */
int Unit::getPlayerID() { //int
    return this->playerID;
};

/**
 * Move this Unit to the given Position if it is empty.
 */
void Unit::move(Position position) { //void
    if (this->moveHelper.isEmpty(position)) {
        this->moveHelper.move(this->currentPosition, position);
        this->currentPosition = position;
    }
};

/**
 * Tell the Unit that it is a new turn.
 */
void Unit::refresh() { //void
    var removeStates = [];
    for (var i in this->_states) {
        var temp = this->_states[i].refreshTurn(this);
        if (temp !== undefined) {
            removeStates[removeStates.length] = temp;
        }
    }
    for (i in removeStates) {
        this->removeState(removeStates[i].name);
    }
};

/**
 * Updates unit's states
 * @returns unit's states
 */
void Unit::updateStates(when, argument) { //void
    var printStrings = [];
    var removeNames = [];
    var removeThis = {};
    for (var i in this->_states) {
        removeThis.remove = false;
        printStrings.push(this->_states[i][when](this, argument,
            removeThis));
        if (removeThis.remove) {
            removeNames.push(this->_states[i].name);
        }
    }
    for (i in removeNames) {
        this->removeState(removeNames[i]);
    }
    return printStrings;
};

/**
 * Adds a State with the given name to the Unit.
 * @param state The number id representing the new State.
 */
void Unit::addState(int state) { //void
    if (staticStates[state] === NULL) {
        return;
    }
    State newState;
    memcpy(newState, &staticStates[state], sizeof State);
    if (newState === undefined) {
        return;
    }

    if (!(this->hasState(state))) {//TODO: make is we can have the same debuff multiple times for some debuffs. Will neeed an event call
        this->states[this->states.size] = newState;
        newState.affect(this);
        return;
    }
};

/**
 * Adds a new Skill to the Unit.
 * @param skill The new Skill to add
*/ 
void Unit::addSkill(Skill skill) { //void
    for (int i = 0; i < skills.size(); i++) {
       if (skills[i].equals(skill)) {
           return false;
       }
    }
    skills.push_back(skill);
    return false;
};
'


/**
 * Removes any State with the given name from the Unit.
 * @param state The name of the State to remove.
 */
void Unit::removeState(int state) { //void 
    State byeState = new State(state);
    if (byeState === undefined) {
        return;
    }
    for (int i = 0; i < this->states.length; i++) {
        if (byeState.equals(this->states[i])) {
            this->states[i].clear(this);
            this->states.erase(i--);
        }
    }
};


/**
 * This Unit's equipped weapon
 * @name Unit#equippedWeapon
 * @type Weapon
 * @readonly
 */
Weapon Unit::getEquippedWeapon(){
    if (this->canWield(this->items[0]) && equipped) {
        return this->items[0];
    }
    return NULL;
   
};

/**
 * This Unit's damage
 * @name Unit#damage
 * @type Damage
 * @readonly
 */
Damage Unit::getAttackDamage() {
    Damage damage = new Damage();
    if (equippedWeapon === NULL) {
        return damage;
    }
    damage.setWeaponType(this->equippedWeapon.getWeaponType());
    damage.setDamageType(this->equippedWeapon.getDamageType();)
     if (equippedWeapon.damageType == PHYSICAL) { //Calculate damage to deal.
        damage.setValue(this->equippedWeapon.damage + this->stats[ATTACK]);
    } else if (equippedWeapon.damageType == MAGICAL) {
        damage.setValue(this->equippedWeapon.damage + this->stats[MAGIC]);
    }
    return damage;
};

/**
 * Attempt to strike the opposing Unit once.
 * @param enemyUnit the enemy Unit to attack
 */
void Unit::engage(Unit enemyUnit) {
    //this->updateStates("onEngageStart");//this should be an event
    //enemyUnit.updateStates("onEngagedStart");//this should be an event
    int randHit;
    int randCrit;
    randHit = rand() % 100;
    randCrit = rand % 100;
    Weapon equippedWeapon = this->equippedWeapon;
    int hit = this->getAccuracy() - enemyUnit.avoid;
    int crit = this->getCrit();
    int damage = this->damage;
    /*
	if (damage.value === 0) {
		return; // we can't attack
	} 
	*/

    if (randHit < hit) { //We hit the enemy
        equippedWeapon.use(this);
        //weaponStatus.isBroken = equippedWeapon.uses <= 0; Our weapons don't break

           //TODO Add an on-hit event
        if (randCrit < crit) {
            damage.originalValue = damage.value;
            damage.value = damage.value * this->critDamage;
            damage.isCritical = true;
        } 
            enemyUnit.takeDamage(damage) 
    }
    //Event here 
    //this->updateStates("onEngageEnd");
    //enemyUnit.updateStates("onEngagedEnd", enemyUnit);
};

/**
 * Attempt a battle against an opposing Unit
 * @param enemyUnit The Unit to attack
 */
void Unit::attackUnit(Unit enemyUnit) { //void
   
    Unit aggresor = this;
    Unit target = enemyUnit;
    Weapon enemyWeapon = target.equippedWeapon;
    int distance = aggresor.position.distanceFrom(target.position);
    bool attackBackable =   (enemyWeapon != NULL) && 
                            enemyUnit.canWield(enemyWeapon) && 
                            enemyWeapon.minRange <= distance &&
                            enemyWeapon.maxRange >= distance;

    //this->updateStates("onAttackStart", attackData); EVENTS
    //enemyUnit.updateStates("onAttackedStart", attackData);

    aggresor.engage(target); //Attack the enemy
    if (attackData.target.hp == 0) { //If they died, it is over; //TODO add an event for ending the battle and killing
        //this->updateStates("onAttackEnd", attackData);
        //enemyUnit.updateStates("onAttackedEnd", attackData);
        return;
    }

    if (attackBackable) {

        attackData.target.engage(attackData.aggresor); //Get attacked in return
        if (attackData.aggresor.hp == 0) { //If we died, it is over;
            //this->updateStates("onAttackEnd", attackData);
            //enemyUnit.updateStates("onAttackedEnd", attackData);
            return;
        }
    }
    if (aggresor.stats<SPEED> > target.stats<SPEED> + 4 ) { //If we are fast, then we attack again

        aggresor.engage(attackData.target);

        if (attackData.target.hp == 0) { //If they died, it is over;
            //this->updateStates("onAttackEnd", attackData);
            //enemyUnit.updateStates("onAttackedEnd", attackData);
            return rands;
        }
    } else if (aggresor.stats<SPEED> + 4 < attackData.target.stats<SPEED> && attackBackable ) { //If they are fast, then have them attack again

        target.engage(aggresor); //Get attacked in return
    }
    //this->updateStates("onAttackEnd", attackData);
    //enemyUnit.updateStates("onAttackedEnd", attackData);
};

/**
 * Have us take the appropriate damage. 
 * @param damage, an object with a damage type and damage to take.
 */
void Unit::takeDamage(Damage damage) { //void
    //this->updateStates("onTakeDamage", damage);
    int value = damage.value;
    if (damage.getDamageType() == PHYSICAL) {
        value -= this->defense;
    } else if (damage.getDamageType() == MAGICAL) {
        value -= this->resistance;
    }
    value *= damage.getMultiplier();
    if (value < 0) { //we don't heal enemies with high resistances when we hit them
        value = 0;
    }
    this->hp -= value;
    if (this->hp <= 0) {
        this->hp = 0;
        this->die();
    }
    this->updateStates("onTookDamage", damage);
};

/**
 * Heals the unit by the designated (positive) amount.
 * @amount amount to heal the Unit. Value of "all" will fully heal the Unit
 */
void Unit::heal(int amount) {
    if (amount > 0) {
        this->.hp += amount;
    }
    if (this->hp > this->maxHP) {
        this->hp = this->maxHP;
    }
};

/**
 * This Unit's accuracy
 * @name Unit#accuracy
 * @type int
 * @readonly
 */
int getAccuracy() {
    if (this->equippedWeapon == NULL) {
        return 0;
    } 
    return this->equippedWeapon.hit + 2 * (this->stats[SKILL]) + this->stats[SPEED];
     
};

/**
 * This Unit's avoid
 * @name Unit#avoid
 * @type int
 * @readonly
 */
int Unit::getAvoid() {
    return 2 * this->stats[SPEED] + this->stats[SKILL];
};

/**
 * TODO
 */
bool Unit::canWield(Item weapon) {
    for (int i = 0; i <weaponTypes.size(); i++) {
        if (weapon !== NULL && this->weaponTypes[i] == weapon.weaponType) {
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
        Item temp = this->items[0];
        this->items[0] = this->items[index];
        this->items[index] = temp;
    }
};

/** Use the Item in the desired Inventory slot
 * @param index the inventory slot to use
 */
void Unit::useItem(int index) {
    if (index > -1 && index < this->_items.size()) {
        return this->items[index].use(this);
    }
};

/**
 * This Unit's position
 * @name Unit#position
 * @type Position
 * @readonly
 */
getPosition() {
    return this->currentPosition;
};
setPosition(Position pos) {
    this->currentPosition = pos;
};
/**
 * This Unit's last position
 * @name Unit#lastPosition
 * @type Position
 * @readonly
 */
Position Unit::getLastPosition() {
     return this->lastPosition;
}
  
void setLastPosition(Position pos) {
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
};

/**
 * This Unit's defense
 * @name Unit#defense
 * @type int
 * @readonly
 */
int Unit::getDefense() {
    return (this->stats[DEFENSE] + this->bonusStats[DEFENSE]) * this->statMultipliers[DEFENSE];
    }
};

/**
 * This Unit's resistance
 * @name Unit#resistance
 * @type int
 * @readonly
 */
int Unit::getResistance() {
    return (this->stats[RESISTANCE] + this->bonusStats[RESISTANCE]) * this->statMultipliers[RESISTANCE];
    }
};

/**
 * This Unit's magic
 * @name Unit#magic
 * @type int
 * @readonly
 */
int Unit::getMagic() {
    return (this->stats[MAGIC] + this->bonusStats[MAGIC]) * this->statMultipliers[MAGIC];
    }
};

/**
 * This Unit's speed
 * @name Unit#speed
 * @type int
 * @readonly
 */
int Unit::getSpeed() {
    return (this->stats[SPEED] + this->bonusStats[SPEED]) * this->statMultipliers[SPEED];
    }
};

/**
 * This Unit's skill
 * @name Unit#skill
 * @type int
 * @readonly
 */
int Unit::getSkill() {
    return (this->stats[SKILL] + this->bonusStats[SKILL]) * this->statMultipliers[SKILL];
    }
};

int Unit::getCharisma() {
    return (this->stats[CHARISMA] + this->bonusStats[CHARISMA]) * this->statMultipliers[CHARISMA];
    }
})
int Unit::getConstitution() {
    return (this->stats[CONSTITUTION] + this->bonusStats[CONSTITUTION]) * this->statMultipliers[CONSTITUTION];
    }
});
/**
 * This Unit's movement
 * @name Unit#movement
 * @type int
 * @readonly
 */
int Unit::getMovement() {
    return this->movement;
    }
});

/**
 * This Unit's playerID
 * @name Unit#playerID
 * @type int
 * @readonly
 */
int Unit::getplayerID() {
    return this->playerID;
    
};

/**
 * This Unit's skills
 * @name Unit#skills
 * @type Skill[]
 * @readonly
 */
std::vector<Skill> Unit::getSkills() {
    return this->skills;
};

/**
 * This Unit's states
 * @name Unit#states
 * @type State[]
 * @readonly
 */
std::vector<State> Unit::getStates() {
    return this->states;
};

/**
 * This Unit's items
 * @name Unit#items
 * @type Item[]
 * @readonly
 */
std::vector<Item> Unit::getItems() {
    return this->items;
};

/**
 * This Unit's stats
 * @name Unit#stats
 * @type int[]
 * @readonly
 */
std::vector<Skill> Unit::getStats() {
    return this->stats;
};


/**
 * This Unit's flying status
 * @name Unit#canFly
 * @type bool
 * @readonly
 */
bool Unit::canFly()
    return this->airTraversable;    
};

/**
 * Called when a unit is dies. Sets the Units state to dead
 */
Unit.prototype.die() {
    this->dead = true;
    this->skillContext.killUnitAtPosition(this->currentPosition);
};

/**
 * This Unit's ranges it can attack
 * @name Unit#ranges
 * @type int[]
 * @readonly
 */
std::vector<int> Unit::getRanges(){ //can have duplicates... for now. I'm lazy
    std::vector<int> ranges = new std::vector<int>();
    for (int i = 0; i <this->items.size; i++) {
        if (this->canWield(this->items[i])) {
            for (var k = this->items[i].minRange; k <=
                this->items[i].maxRange; k++) {
                ranges.push(k);
            }
        }
    }
    return ranges;
};

/**
 * This Unit's ranges it can attack with its equipped weapon
 * @name Unit#equippedRanges
 * @type int[]
 * @readonly
 */
std::vector<int> Unit::getEquipedRanges(){
    std::vector<int> ranges = new std::vector<int>();
        for (var k = this->equippedWeapon.minRange; k <=this->equippedWeapon.maxRange; k++) {
            ranges.push(k);
        }
    }
    return ranges;
};

/**
 * This Unit's SkillContext
 * @name Unit#skillContext
 * @type SkillContext
 * @readonly
 */
SkillContext* Unit::getSkillCOntext() {
    return this->skillContext;
};