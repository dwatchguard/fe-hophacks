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
	if (getAdjacentEnemys(unit).length > 0) {
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
	for (int i = 0; i < game->getMap().width(); i++) {
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
	if (getEnemysWithin(unit, range).length > 0) {
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
	getUnitsWithin(unit->getPosition(), range, &arr, unit->getplayerID(),"enemy");
	return arr;
};

/**
* Determines if there are any allied adjacent units to the given Unit.
* @param {Unit} unit The unit to search around.
* @return true if there is an allied adjacent Unit, false otherwise.
*/
SkillContext.prototype.hasAdjacentAlly = function(unit) {
	if (this.getAdjacentAllies(unit).length > 0) {
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
SkillContext.prototype.getAdjacentAllies = function(unit) {
	return this.getAlliesWithin(unit, 1);
};

/**
* Determines if any allied Units are within range of the Unit.
* @param {Unit} unit The unit to look around.
* @param {int} range The range to use around.
* @return True if there is an ally Unit within the range, false otherwise.
*/
SkillContext.prototype.hasAllyWithin = function(unit, range) {
	if (this.getAlliesWithin(unit, range).length > 0) {
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
SkillContext.prototype.getAlliesWithin = function(unit, range) {
	var arr = [];
	this._getUnitsWithin(unit.position, range, arr, unit.playerID,
		"ally");
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
SkillContext.prototype.getAlliesWithinPos = function(unit, range,
	otherPosition) {
	var arr = [];
	this._getUnitsWithin(otherPosition, range, arr, unit.playerID,
		"ally");
	return arr;
};

/**
* Gives a Set that holds all enemy Units within the given range behind the enemy Unit.
* @param {Unit} unit The allied unit.
* @param {int} range The range behind the enemy unit.
* @param {Unit} enemyUnit The unit to check behind.
* @return A set of Units whose position is within range of and behind the given enemy Unit.
* The set may be empty.
*/
SkillContext.prototype.getEnemiesBehind = function(unit, range,
	enemyUnit) {
	var arr = [];
	var xpos = enemyUnit.position.x - unit.position.x;
	var slope = (enemyUnit.position.y - unit.position.y) / (
		enemyUnit.position.x - unit.position.x);
	var enemies = this.getAlliesWithin(enemyUnit, range);
	for (var i in enemies) {
		var checkXpos = enemies[i].position.x - enemyUnit.position
			.x;
		var checkSlope = (enemies[i].position.y - enemyUnit.position
			.y) / (enemies[i].position.x - enemyUnit.position
				.x);
		if (checkSlope == slope) {
			if (slope != = 0 || (slope == = 0 && xpos / checkXpos >
				0)) {
				arr.push(enemies[i]);
			}
		}
	}
	return arr;
};

/**
* Moves a unit to the given position.
* @param {Unit} unit The unit to move.
* @param {Position} position The position to move the unit to.
*/
SkillContext.prototype.moveUnit = function(unit, position) {
	this._game.map.moveUnit(unit.position, position);
};

/**
* Determines if any units are in a particular Position.
* @param {Position} position The position to check.
* @return true if the Position is empty, false otherwise.
*/

SkillContext.prototype.isEmpty = function(position) {
	return !this._game.map.getGridCell(position).hasUnit();
};

/**
* Gets the unit in a particular Position.
* @param {Position} position The position to check.
* @return The unit if there is one, null otherwise.
*/

SkillContext.prototype.getUnit = function(position) {
	if (this.isEmpty(position)) {
		return null;
	}
	return this._game.map.getUnit(position);
};

/**
* Kills a unit.
* @param {Position} position The position of the unit.
* @return true if a unit is killed, false otherwise.
*/
SkillContext.prototype.killUnitAtPosition = function(position) {
	return this._game.map.removeUnit(position);
};

/**
* Tell the Game that the Game State may have changed and to update everything.
*/
SkillContext.prototype.updateGame = function() {
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
SkillContext.prototype._getUnitsWithin = function(position, range,
	arr, playerID, alignment) {
	var map = {};
	for (var i = 0; i <= range; i++) {
		for (var j = 0; j <= range - i; j++) {
			var posArr = [new Position(position.x + j, position.y +
				i),
				new Position(position.x - j, position.y + i),
				new Position(position.x + j, position.y - i),
				new Position(position.x - j, position.y - i)
			];
			for (var k = 0; k < posArr.length; k++) {
				if (this._checkPosition(posArr[k], playerID,
					alignment)) {
					map[JSON.stringify(posArr[k])] = this._game.map
						.getGridCell(posArr[k]).unit;
				}
			}
		}
	}
	delete map[JSON.stringify(new Position(position.x, position.y))];
	for (var key in map) {
		arr.push(map[key]);
	}
};

SkillContext.prototype._checkPosition = function(position, playerID,
	alignment) {
	var gridCell = this._game.map.getGridCell(position);
	if (gridCell != = null && gridCell.hasUnit()) {
		if (alignment == "any") {
			return true;
		}
		else if (alignment == "ally" && gridCell.unit.playerID ==
			playerID) {
			return true;
		}
		else if (alignment == "enemy" && gridCell.unit.playerID !=
			playerID) {
			return true;
		}
		return false;
	}
};

/**
* This SkillContexts's gameTurnNumber
* @name SkillContext#gameTurnNumber
* @type unt
* @readonly
*/
Object.defineProperty(SkillContext.prototype, 'gameTurnNumber', {
get: function() {
	return this._game.turnNumber;
}
});

module.exports = SkillContext;