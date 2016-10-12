#ifndef OfflineGame_H
#define OfflineGame_H
    
class OflineGame {
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
    OfflineGame::OfflineGame(int gameID, &Team team1, &Team team2, ) {}

/**
 * Updates game state.
 */
    void OfflineGame::update() {}

/**
 * Start a new Turn.
 */
    void OfflineGame::newTurn(){}

/**
 * Execute a command
 * @param command the command to execute
 */
    void OfflineGame::Command(Command command) {}

/**
 * Execute command based on type
 */
    OfflineGame::ExecuteCommands(Command command) = {}

/**
 * Checks if a command is valid based on type
 */
    bool OfflineGame::isValidCommand(Command command) = {}

/**
 * Checks if the game is over
 * @returns whether or not the game is over
 */
    bool OfflineGame::gameOver = function() {}

/**
 * This Game's map
 * @name Unit#map
 * @type GameMap
 * @readonly
 */
    Map OfflineGame::getMap()

/**
 * This Game's turnNumber
 * @name Unit#turnNumber
 * @type int
 * @readonly
 */
    int OfflineGame getTurnNumber::()


OfflineGame::checkChain(Unit unit) {}

/**
 * Gets a list of all of the units in the game.
 * @return The array of units.
 */
    Unit* OfflineGame::getUnits = function() {}

/**
 * Gets an array of enemy units' positions.
 * @return The array of positions.
 */
   Position* OfflineGame::getEnemyPositions () {}

/**
 * Gets an array of enemy units' cells.
 * @return The array of cells.
 */
    Cell* OfflineGame::getEnemyCells() {}

/**
 * Gets the cells a unit can move to.
 * @param {Unit} The unit to check.
 * @return An array containing the accessible cells.
 */
    Cell* OfflineGame::getAccessibleCells(Unit unit) {}

/**
 * Gets the Positions a unit can move to.
 * @param {Unit} The unit to check.
 * @return An array containing the accessible Positions.
 */
    Position* OfflineGame::getAccessiblePositions(Unit unit) {}

/**
 * Gets the Cells a unit can attack before it moves.
 * @param {Unit} The selected unit.
 * @return An array containing the Cells that can be attacked.
 */
    Cell* OfflineGame::getAttackableCells(Unit unit) {
    
};

/**
* Gets all the Cells a unit can attack before or after it moves.
* @param {Unit} The selected unit.
* @return An array containing the all Cells that can be attacked.
*/
    Cell* OfflineGame::getAllAttackableCells(Unit unit) {}

/**
* Gets the Positions a unit can attack before it moves.
* @param {Unit} The selected unit.
* @return An array containing the Positions that can be attacked.
*/
    Position* OfflineGame::getAttackablePositions(Unit unit) {}

/**
 * Gets a unit's attackable cells after it has moved.
 * @param {Unit} The unit that was moved.
 * @return An array containing the Cells that can be attacked.
 */
    Cell* OfflineGame::getAttackableCellsAfterMove(Unit unit) {}

/**
 * Gets all a unit's attackable cells after it has moved.
 * @param {Unit} The unit that was moved.
 * @return An array containing the Cells that can be attacked.
 */
    Cell* OfflineGame::getAllAttackableCellsAfterMove(Unit unit) {}

/**
 * Gets the Unit at the given Position.
 * @param {Position} position The Position to check.
 * @return The Unit at the Position.
 */
    Unit OfflineGame::OfflineGame::getUnitAtPosition(Position position) {}

/**
 * Return an array containing pointers to the functions a unit can do after it moves.
 * @param {Unit} unit The unit that was moved.
 * @return an array containing pointers to the functions a unit can do after it moves.
 */
    void** OfflineGame::getOptions(Unit unit) {}

/**
 * Returns an object containing the weapons a unit can equip.
 * @param {Unit} unit The unit to check.
 * @return An object whose keys are item names and values are indices.
 */
    Weapon* OfflineGame::getWeapons(Unit unit) {}

/**
 * Returns an object containing the consumables a unit can use.
 * @param {Unit} unit The unit to check.
 * @return An object whose keys are item names and values are indices.
 */
    Consumables* OfflineGame::getConsumables(Unit unit) (}

/**
 * Gets if the current turn is ours
 * @return True if our turn, else false;
 */
    bool OfflineGame::isOurTurn = function() {}

/**
 * Determines if a command is valid.
 * @param command The command to check.
 * @return true if it's valid, false otherwise.
 */
    bool OfflineGame::isValid = function(Command command) {}
};
#endif