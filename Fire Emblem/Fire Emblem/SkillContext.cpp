#include "SkillContext.h"


/**
* Represents a skill context.
* @constructor
* @param {Game} thisGame - The current game.
*/
SkillContext::SkillContext(Game* thisGame) {
	game = thisGame;
}

/**
* Determines if the given Unit has any adjacent enemy Units.
* @param {Unit} unit The unit to look around.
* @return True if an adjacent position has an enemy, false otherwise.
*/
bool SkillContext::hasAdjacentEnemy(Unit* unit) {
	if (getAdjacentEnemys(unit).size() > 0) {
		return true;
	}
	return false;
};
/**
* Returns all Empty Grid Cells
* @return An Array with every empty GridCell.
*/
std::vector<Cell> SkillContext::allEmptyCells() {
	std::vector<Cell> cells;
	for (int i = 0; i < game->getMap()->width(); i++) {
		for (int j = 0; j < game->getMap()->hieght(); j++) {
			if (game->getMap()->getCell(i, j)->getUnit() == NULL) {
				cells.push_back(game->getMap()->getCell(i, j)->getUnit());
			}
		}
	}
	return cells;
};

/**
* Gives a Set that holds all adjacent enemy Units.
* @param {Unit} unit The unit to look around.
* @return A set of Units whose position is adjacent to the Given Unit.
* The set may be empty.
*/
std::vector<Unit*> SkillContext::getAdjacentEnemys(Unit* unit) {
	return getEnemysWithin(unit, 1);
};

/**
* Determines if any Enemy Units are within range of the Unit.
* @param {Unit} unit The unit to look around.
* @param {int} range The range to use around.
* @return True if there is an enemy Unit within the range, false otherwise.
*/
bool SkillContext::hasEnemyWithin(Unit* unit, int range) {
	if (getEnemysWithin(unit, range).size() > 0) {
		return true;
	}
	return false;
};

/**
* Gives a set that holds all enemy Units within the given range.
* @param {Unit} unit The unit to look around.
* @param {int} range The range to use around.
* @return A set of Units whose position within range of Given Unit.
* The set may be empty.
*/
std::vector<Unit*> SkillContext::getEnemysWithin(Unit* unit,int range) {
	std::vector<Unit*> arr;
	getUnitsWithin(unit->getPosition(), range, &arr, unit->getplayerID());
	return arr;
};

/**
* Determines if there are any allied adjacent units to the given Unit.
* @param {Unit} unit The unit to search around.
* @return true if there is an allied adjacent Unit, false otherwise.
*/
bool SkillContext::hasAdjacentAlly(Unit* unit) {
	if (getAdjacentAllies(unit).size() > 0) {
		return true;
	}
	return false;
};

/**
* Gives a Set that holds all adjacent allied Units.
* @param {Unit} unit The unit to look around.
* @return A set of Units whose position is adjacent to the Given Unit.
* The set may be empty.
*/
std::vector<Unit*> SkillContext::getAdjacentAllies(Unit *unit) {
	return getAlliesWithin(unit, 1);
};

/**
* Determines if any allied Units are within range of the Unit.
* @param {Unit} unit The unit to look around.
* @param {int} range The range to use around.
* @return True if there is an ally Unit within the range, false otherwise.
*/
bool SkillContext::hasAllyWithin(Unit* unit, int range) {
	if (getAlliesWithin(unit, range).size() > 0) {
		return true;
	}
	return false;
};

/**
* Gives a Set that holds all allied Units within the given range.
* @param {Unit} unit The unit to look around.
* @param {int} range The range to use around.
* @return A set of Units whose position is within range of the given Unit.
* The set may be empty.
*/
std::vector<Unit*> SkillContext::getAlliesWithin(Unit* unit, int range) {
	std::vector<Unit*> arr;
	getUnitsWithin(unit->getPosition(), range, &arr, unit->getPlayerID());
	return arr;
};

/**
* Gives a Set that holds all allied Units within the given range of a position.
* @param {Unit} unit The unit looking for allies.
* @param {int} range The range to use around.
* @param {Position} otherPosition The position to check around for allies.
* @return A set of Units whose position is within range of the given position.
* The set may be empty.
*/
std::vector<Unit*> SkillContext::getAlliesWithinPos(int playerID, int range, Position otherPosition) {
	std::vector<Unit*> arr;
	getUnitsWithin(otherPosition, range, &arr, playerID);
	return arr;
};


/**
* Moves a unit to the given position.
* @param {Unit} unit The unit to move.
* @param {Position} position The position to move the unit to.
*/
void SkillContext::moveUnit(Unit* unit, Position position) {
	game->getMap()->moveUnit(unit->getPosition(), position);
};

/**
* Determines if any units are in a particular Position.
* @param {Position} position The position to check.
* @return true if the Position is empty, false otherwise.
*/

bool SkillContext::isEmpty(Position position) {
	return !game->getMap()->getGridCell(position)->hasUnit();
};

/**
* Gets the unit in a particular Position.
* @param {Position} position The position to check.
* @return The unit if there is one, null otherwise.
*/

Unit* SkillContext::getUnit(Position position) {
	if (isEmpty(position)) {
		return NULL;
	}
	return game->getMap()->getUnit(position);
};

/**
* Kills a unit.
* @param {Position} position The position of the unit.
* @return true if a unit is killed, false otherwise.
*/
void SkillContext::killUnitAtPosition(Position position) {
	return game->getMap()->removeUnit(position);
};

/**
* Tell the Game that the Game State may have changed and to update everything.
*/
void SkillContext::updateGame() {
	// todo
};

/**
* Adds units to the given array based on the range, their distance from the given position, and their alignment.
* @private
* @param {Position} position The position to check.
* @param {int} range The range of movement to check for units.
* @param {Array} arr The array to fill with alignment matching units.
* @param {int} playerID The playerID of the unit that is being matched up against to determine alignment.
* @param {String} alignment The alignment of the units to be added to the array.
*/
void SkillContext::getUnitsWithin(Position position, int range, std::vector<Unit*>* arr, int playerID) {
	std::map<Position, Unit*> map;
	std::vector<Unit*> units;
	for (int i = 1; i <= range; i++) {
		for (int j = 1; j <= range - i; j++) {
			Position posArr[4];// = Position[4];
			posArr[0] = Position(position.getX() + j, position.getY() + i);
			posArr[1] = Position(position.getX() + j, position.getY() - i);
			posArr[2] = Position(position.getX() - j, position.getY() + i);
			posArr[3] = Position(position.getX() - j, position.getY() - i);
			for (int k = 0; k < 4; k++) {
				if (checkPosition(posArr[k], playerID)) {
					map.insert(std::pair<Position, Unit*>(posArr[k], game->getMap()->getGridCell(posArr[k])->getUnit()));
				}
			}
		}
	}
	std::map<Position, Unit*>::iterator it;
	for (it = map.begin(); it != map.end(); ++it) {
		arr->push_back(it->second);
	}
};

bool SkillContext::checkPosition(Position position, int playerID) {
	Cell* gridCell = game->getMap()->getGridCell(position);
	if (gridCell != NULL && gridCell->hasUnit()) {
		if (gridCell->getUnit()->getPlayerID() == playerID) {
			return true;
		}
		return false;
	}
	return false;
};

/**
* This SkillContexts's gameTurnNumber
* @name SkillContext#gameTurnNumber
* @type unt
* @readonly
*/
int SkillContext::getGameTurnNumber() {
	return game->getTurnNumber();
};
