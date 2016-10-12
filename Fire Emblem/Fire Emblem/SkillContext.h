#pragma once
#include "stdafx.h"

class SkillContext
{
	Game* game;
public:
	/**
	* Represents a skill context.
	* @constructor
	* @param {Game} thisGame - The current game.
	*/
	SkillContext(Game* thisGame); 

	/**
	* Determines if the given Unit has any adjacent enemy Units.
	* @param {Unit} unit The unit to look around.
	* @return True if an adjacent position has an enemy, false otherwise.
	*/
	bool hasAdjacentEnemy(Unit* unit);
	/**
	* Returns all Empty Grid Cells
	* @return An Array with every empty GridCell.
	*/
	std::vector<Cell> allEmptyCells();

	/**
	* Gives a Set that holds all adjacent enemy Units.
	* @param {Unit} unit The unit to look around.
	* @return A set of Units whose position is adjacent to the Given Unit.
	* The set may be empty.
	*/
	std::vector<Unit*> getAdjacentEnemys(Unit* unit);

	/**
	* Determines if any Enemy Units are within range of the Unit.
	* @param {Unit} unit The unit to look around.
	* @param {int} range The range to use around.
	* @return True if there is an enemy Unit within the range, false otherwise.
	*/
	bool hasEnemyWithin(Unit* unit, int range);

	/**
	* Gives a set that holds all enemy Units within the given range.
	* @param {Unit} unit The unit to look around.
	* @param {int} range The range to use around.
	* @return A set of Units whose position within range of Given Unit.
	* The set may be empty.
	*/
	std::vector<Unit*> getEnemysWithin(Unit* unit, int range);

	/**
	* Determines if there are any allied adjacent units to the given Unit.
	* @param {Unit} unit The unit to search around.
	* @return true if there is an allied adjacent Unit, false otherwise.
	*/
	bool SkillContext::hasAdjacentAlly(Unit* unit);

	/**
	* Gives a Set that holds all adjacent allied Units.
	* @param {Unit} unit The unit to look around.
	* @return A set of Units whose position is adjacent to the Given Unit.
	* The set may be empty.
	*/
	std::vector<Unit*> SkillContext::getAdjacentAllies(Unit* unit);

	/**
	* Determines if any allied Units are within range of the Unit.
	* @param {Unit} unit The unit to look around.
	* @param {int} range The range to use around.
	* @return True if there is an ally Unit within the range, false otherwise.
	*/
	bool SkillContext::hasAllyWithin(Unit* unit,int range);

	/**
	* Gives a Set that holds all allied Units within the given range.
	* @param {Unit} unit The unit to look around.
	* @param {int} range The range to use around.
	* @return A set of Units whose position is within range of the given Unit.
	* The set may be empty.
	*/
	std::vector<Unit*> SkillContext::getAlliesWithin(Unit* unit, int range);

	/**
	* Gives a Set that holds all allied Units within the given range of a position.
	* @param {int} unit playerID of allies.
	* @param {int} range The range to use around.
	* @param {Position} otherPosition The position to check around for allies.
	* @return A set of Units whose position is within range of the given position.
	* The set may be empty.
	*/
	std::vector<Unit*> SkillContext::getAlliesWithinPos(int playerID, int range, Position pos);

	/**
	* Moves a unit to the given position.
	* @param {Unit} unit The unit to move.
	* @param {Position} position The position to move the unit to.
	*/
	void SkillContext::moveUnit(Unit* unit, Position position);

	/**
	* Determines if any units are in a particular Position.
	* @param {Position} position The position to check.
	* @return true if the Position is empty, false otherwise.
	*/

	bool SkillContext::isEmpty(Position position);

	/**
	* Gets the unit in a particular Position.
	* @param {Position} position The position to check.
	* @return The unit if there is one, null otherwise.
	*/

	Unit* SkillContext::getUnit(Position position);

	/**
	* Kills a unit.
	* @param {Position} position The position of the unit.
	* @return true if a unit is killed, false otherwise.
	*/
	void SkillContext::killUnitAtPosition(Position position);

	/**
	* Tell the Game that the Game State may have changed and to update everything.
	*/
	void SkillContext::updateGame () {
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
	std::vector<Unit*> SkillContext::getUnitsWithin(Position position, int range, int playerID);

	/**
	* This SkillContexts's gameTurnNumber
	* @name SkillContext#gameTurnNumber
	* @type unt
	* @readonly
	*/
	int getGameTurnNumber();

};

