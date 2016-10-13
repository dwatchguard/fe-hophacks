#include "stdafx.h"
#include "OfflineGame.h"


/**
* Represents a Game Object
* @constructor
* @param someInput this will be formatting telling the game what kind of Game it is
* @param team1 Json of Team 1
* @param team2 Json of Team 2
*/
OfflineGame::OfflineGame(int gameID, Team &team1, Team &team2) {
	this->gameType = new GameType(ROUT);
	this->turnNumber = -1;
	this->skillContext = new SkillContext(*this);
	this->teams = [new Team(team1, 0, this->skillContext), new Team(
		team2, 1, this->skillContext)];
	this->map = new Map(gameID, team1, team2);
	this->moveHelper = new MoveHelper(this->map);
	this->lastCommandedUnit = NULL;
	this->inCommandChain = false;
	//this->timer = new Timer(this->newTurn.bind(this), 150000 /*milliseconds*/ );
	//Skill.prototype.skillContext = skillContext;
}

/**
* Updates game state.
*/
void OfflineGame::update() {}; //this was unsused before, keeping it just in case

							   /**
							   * Start a new Turn.
							   */
OfflineGame::newTurn() {
	this->turnNumber++;
	this->teams[(this->turnNumber) % 2].startTurn();
	this->lastCommandedUnit = NULL;
	this->inCommandChain = false;
	//this->timer.restart();
};

/**
* Execute a command
* @param command the command to execute
*/
void OfflineGame::executeCommand(command) {
	//var unit = this->map.moveUnit(command.unitPosition, command.destination);
	this->formatCommand[command.commandType](command);

	if (this->isValidCommand[command.commandType](command, this) &&
		command.playerID == this->turnNumber % 2) { //check to make sure you can only command on your turn
		this->lastCommandedUnit = this->map.getUnit(command.unitPosition);
		var returnCommand = this->executeCommands[command.commandType]
		(command, this);
		if (this->teams[this->turnNumber % 2].isDone()) {
			this->newTurn();
		}

		return returnCommand;
	}
};

/**
* Execute command based on type
*/
void OfflineGame::moveUnit(Position unitPosition, Position destination) {
	this->map.moveUnit(command.unitPosition, command.destination);
	this->inCommandChain = true;
};

void OfflineGame::undoMove(Position unitPosition) {
	this->map.unmoveUnit(unitPosition);
	this->inCommandChain = false;
};

void OfflineGame::equip(Position unitPosition, int itemIndex) {
	this->map.getUnit(unitPosition).equip(itemIndex);
};

void OfflineGame::useItem(Position unitPosition, int itemIndex) {
	this->map.getUnit(unitPosition).useItem(itemIndex);
	this->inCommandChain = false;
	this->map.getUnit(unitPosition).tire()
};

void OfflineGame::wait(Position unitPosition) {
	this->map.getUnit(command.unitPosition).tire();
	this->inCommandChain = false;
};

void OfflineGame::attack(Position unitPosition, Position targetPosition) {
	Unit unit = this->map.getUnit(command.unitPosition);
	Unit enemyUnit = this->map.getUnit(command.targetPosition);
	Unit.tire();
	unit.attackUnit(enemyUnit);
	this->inCommandChain = false;
};

void OfflineGame::activateSkill(Position unitPosition) {
	Unit unit = this->map.getUnit(unitPosition);
	unit.skills[command.index].activate(command.targetPosition); //use the skill
	if (unit.skills[command.index].skillType == ACTIVECHAINABLE) {
		this->inCommandChain = true;
	}
	else if (unit.skills[command.index].skillType == ACTIVEWAIT) {
		this->inCommandChain = false;
		unit.tire();
	}
};
/*
toggleTimer: function(command, game) {
game.timer.toggle();
if (typeof window == 'undefined') {
return command;
}
};
*/
void OfflineGame::end: function() {
	this->newTurn();
}
};

/**
* Formats a command based on type
*/


/**
* Checks if the game is over
* @returns whether or not the game is over
*/
void OfflineGame::gameOver() {
	return this->gameMode.isGameOver(this*);
};

/**
* Checks if the game is over based on game type
* @returns whether or not the game is over
*/
/* Move this to the rout.cc file
OfflineGame::isGameOver = {
rout: function(game) {
var alive = 0;
for (var i in this->teams[0].units) {
alive += this->teams[0].units[i].hp;
}
if (alive === 0) {
return 1;
}
alive = 0;
for (i in this->teams[1].units) {
alive += this->teams[1].units[i].hp;
}
if (alive === 0) {
return 0;
}
return -1;
}
};
*/
/**
* This Game's map
* @name Unit#map
* @type GameMap
* @readonly
*/
Map OfflineGame::getMap() {
	return this->map;
};

/**
* This Game's turnNumber
* @name Unit#turnNumber
* @type int
* @readonly
*/
int OfflineGame::getTurnNumber() {
	return this->turnNumber;
};



bool OfflineGame::checkChain(Unit *unit) {
	if (unit == NULL || || unit.isTired()) { //If the Unit is tired or non existant
		return false;
	}
	if (this->inCommandChain && unit != this->lastCommandedUnit)) { //If we are in a chain, but are trying to use another unit.
	return false;
	}
	return true;
};

/**
* Gets a list of all of the units in the game.
* @return The array of units.
*/
std::vector<(Unit*)> OfflineGame::getUnits() {
	std::vector<(Unit*)> units = new  std::vector<(Position)>();
	units.reserve(teams[0].units.size() + teams[1].units.size()); // preallocate memory, saves a little time
	units.insert(units.end(), teams[0].units.begin(), teams[0].units.end());
	units.insert(units.end(), teams[1].units.begin(), teams[1].units.end());
	return units;
};

/**
* Gets an array of enemy units' positions.
* @return The array of positions.
*/
std::vector<(Position)> OfflineGame::getEnemyPositions(int teamID) {
	std::vector<(Position)> arr = new  std::vector<(Position)>();
	int enemyTeamID = (teamID + 1) % 2;
	for (int i = 0; i < this->teams[enemyTeamID].units.length; i++) {
		if (this->teams[enemyTeamID].units[i]->getPosition() != NULL) {
			arr.[i] = (this->teams[enemyTeamID].units[i]->getPosition());
		}
	}
	return arr;
};

/**
* Gets an array of enemy units' cells.
* @return The array of cells.
*/
std::vector<(Cell*)> OfflineGame::getEnemyCells(int teamID) {
	std::vector<(Cell*)> arr = new std::vector<(Cell*)>();
	int enemyTeamID = (this->gameID + 1) % 2;
	for (int i = 0; i < this->teams[enemyTeamID].units.length; i++) {
		if (this->teams[enemyTeamID].units[i]->position != = NULL) {
			arr[i] = this->map.getGridCell(this->teams[enemyTeamID].units[i].->getPosition());
		}
	}
	return arr;
};

/**
* Gets the cells a unit can move to.
* @param {Unit} The unit to check.
* @return An array containing the accessible cells.
*/
std::vector<(Cell*)> OfflineGame::getAccessibleCells(Unit unit) {
	return this->moveHelper.accessibleCells(unit);
};

/**
* Gets the Positions a unit can move to.
* @param {Unit} The unit to check.
* @return An array containing the accessible Positions.
*/
OfflineGame::getAccessiblePositions(Unit unit) {
	std::vector<(Cell*)> cells = this->getAccessibleCells(unit);
	std::vector<(Position)> arr = new std::vector<(Position)>();
	for (int i = 0; i <cells.size(); i++) {
		arr[i] = (cells[i]->getPosition());
	}
	return arr;
};

/**
* Gets the Cells a unit can attack before it moves.
* @param {Unit} The selected unit.
* @return An array containing the Cells that can be attacked.
*/
std::vector<(Cell*)> OfflineGame::getAttackableCells(Unit unit) {
	return this->moveHelper.attackableCells(unit);
};

/**
* Gets all the Cells a unit can attack before it moves.
* @param {Unit} The selected unit.
* @return An array containing the all Cells that can be attacked.
*/
std::vector<(Cell*)> OfflineGame::getAllAttackableCells(Unit unit) {
	return this->moveHelper.allAttackableCells(unit);
};

/**
* Gets the Positions a unit can attack before it moves.
* @param {Unit} The selected unit.
* @return An array containing the Positions that can be attacked.
*/
std::vector<(Position)> OfflineGame::getAttackablePositions(Unit unit) {
	std::vector<(Cell*)> cells = this->getAttackableCells(unit);
	std::vector<(Position)> arr = new std::vector<(Position)>();
	for (int i = 0; i <cells.size(); i++) {
		arr[i] = (cells[i]->getPosition());
	}
	return arr;
};

/**
* Gets a unit's attackable cells after it has moved.
* @param {Unit} The unit that was moved.
* @return An array containing the Cells that can be attacked.
*/
OfflineGame::getAttackableCellsAfterMove(unit) {
	return this->moveHelper.attackableCellsAfterMove(unit, unit.equippedRanges);
};

/**
* Gets the Unit at the given Position.
* @param {Position} position The Position to check.
* @return The Unit at the Position.
*/
OfflineGame::getUnitAtPosition(position) {
	return this->map.getUnit(position);
};

/**
* Return an object containing the things a unit can do after it moves.
* @param {Unit} unit The unit that was moved.
* @return An object whose keys are options.
*/
std::vector<Option> OfflineGame::getOptions(Unit* unit) {
	std::vector<Option> options = new std::vector<Option>();

	var attack = "Attack";
	options[attack] = {};
	this->moveHelper.cellsWithinWeaponRange(unit, unit.position,
		options[attack]);

	var item = "Item";
	options[item] = {};
	for (var i in unit.items) {
		var itemName = unit.items[i].name;
		if (unit.items[i].constructor.name == "Weapon" && unit.canWield(
			unit.items[i])) {
			options[item][itemName] = "Weapon";
		}
		else if (unit.items[i].constructor.name == "Consumable") {
			options[item][itemName] = "Consumable";
		}
	}

	var skills = "Skills";
	options[skills] = {};
	for (var j in unit.skills) {
		if (unit.skills[j].isReady()) {
			options[skills][unit.skills[j].name] = j;
			options[unit.skills[j].name] = true;
		}
	}

	options.Wait = true;

	return options;
};

/**
* Returns an object containing the weapons a unit can equip.
* @param {Unit} unit The unit to check.
* @return An object whose keys are item names and values are indices.
*/
OfflineGame::getEquippableWeapons(unit) {
	var weapons = {};
	for (var i in unit.items) {
		if (unit.items[i].constructor.name == "Weapon" && unit.canWield(
			unit.items[i])) {
			weapons[unit.items[i].name] = i;
		}
	}
	return weapons;
};

/**
* Returns an object containing the consumables a unit can use.
* @param {Unit} unit The unit to check.
* @return An object whose keys are item names and values are indices.
*/
OfflineGame::getConsumables(unit) {
	var items = {};
	for (var i in unit.items) {
		if (unit.items[i].constructor.name == "Consumable") {
			items[unit.items[i].name] = i;
		}
	}
	return items;
};

/**
* Gets if the current turn is ours
* @return True if our turn, else false;
*/
OfflineGame::isOurTurn() {
	return this->turnNumber % 2 == = 1;


};

/**
* Determines if a command is valid.
* @param command The command to check.
* @return true if it's valid, false otherwise.
*/
OfflineGame::isValid(command) {
	this->formatCommand[command.commandType](command);
	if (this->isValidCommand[command.commandType](command, this)) {
		return true;
	}
	return false;
};