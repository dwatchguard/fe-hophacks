#pragma once
#include "Game.h"
class OfflineGame : public Game{
	GameType gameType;
	int turnNumber = 0;
	Skill Context skillContext;
	Team[2] teams;
	Map map;
	MoveHelper moveHelper;
	Unit lastCommandedUnit = NULL;
	bool inCommandChain = false;

	/**
	* Represents a Game Object
	* @constructor
	* @param gameID this will be telling the game what kind of Game it is by looking it up.
	* @param team1 pointer to Team 1
	* @param team2 pointer to Team 2
	*/
	OfflineGame::OfflineGame(int gameID, Team &team1, Team &team2, );

	/**
	* Updates game state.
	*/
	void update();

	/**
	* Start a new Turn.
	*/
	void newTurn();

	/**
	* Execute a command
	* @param command the command to execute
	*/
	void Command(Command command);

	/**
	* Execute command based on type
	*/
	ExecuteCommands(Command command);

		/**
		* Checks if a command is valid based on type
		*/
	bool isValidCommand(Command command);

		/**
		* Checks if the game is over
		* @returns whether or not the game is over
		*/
	bool gameOver();

	/**
	* This Game's map
	* @name Unit#map
	* @type GameMap
	* @readonly
	*/
	Map getMap();

		/**
		* This Game's turnNumber
		* @name Unit#turnNumber
		* @type int
		* @readonly
		*/
	int OfflineGame getTurnNumber::();


	checkChain(Unit unit);

	/**
	* Gets a list of all of the units in the game.
	* @return The array of units.
	*/
	Unit* getUnits();

	/**
	* Gets an array of enemy units' positions.
	* @return The array of positions.
	*/
	Position* getEnemyPositions();

	/**
	* Gets an array of enemy units' cells.
	* @return The array of cells.
	*/
	Cell* getEnemyCells();

	/**
	* Gets the cells a unit can move to.
	* @param {Unit} The unit to check.
	* @return An array containing the accessible cells.
	*/
	Cell* getAccessibleCells(Unit unit);

	/**
	* Gets the Positions a unit can move to.
	* @param {Unit} The unit to check.
	* @return An array containing the accessible Positions.
	*/
	Position* getAccessiblePositions(Unit unit);

	/**
	* Gets the Cells a unit can attack before it moves.
	* @param {Unit} The selected unit.
	* @return An array containing the Cells that can be attacked.
	*/
	Cell* getAttackableCells(Unit unit);

	/**
	* Gets all the Cells a unit can attack before or after it moves.
	* @param {Unit} The selected unit.
	* @return An array containing the all Cells that can be attacked.
	*/
	Cell* getAllAttackableCells(Unit unit);

	/**
	* Gets the Positions a unit can attack before it moves.
	* @param {Unit} The selected unit.
	* @return An array containing the Positions that can be attacked.
	*/
	Position* getAttackablePositions(Unit unit);

	/**
	* Gets a unit's attackable cells after it has moved.
	* @param {Unit} The unit that was moved.
	* @return An array containing the Cells that can be attacked.
	*/
	Cell* getAttackableCellsAfterMove(Unit unit);

	/**
	* Gets all a unit's attackable cells after it has moved.
	* @param {Unit} The unit that was moved.
	* @return An array containing the Cells that can be attacked.
	*/
	Cell* getAllAttackableCellsAfterMove(Unit unit);

	/**
	* Gets the Unit at the given Position.
	* @param {Position} position The Position to check.
	* @return The Unit at the Position.
	*/
	Unit getUnitAtPosition(Position position);

	/**
	* Return an array containing pointers to the functions a unit can do after it moves.
	* @param {Unit} unit The unit that was moved.
	* @return an array containing pointers to the functions a unit can do after it moves.
	*/
	void** getOptions(Unit unit);

	/**
	* Returns an object containing the weapons a unit can equip.
	* @param {Unit} unit The unit to check.
	* @return An object whose keys are item names and values are indices.
	*/
	Weapon* getWeapons(Unit unit);

	/**
	* Returns an object containing the consumables a unit can use.
	* @param {Unit} unit The unit to check.
	* @return An object whose keys are item names and values are indices.
	*/
	Consumables* getConsumables(Unit unit);


/**
* Determines if a command is valid.
* @param command The command to check.
* @return true if it's valid, false otherwise.
*/
	bool isValid(Command command);
};

