#include "stdafx.h"
#include "Cell.h"


/**
* Represents a grid cell.
* @constructor
* @param {Position} pos - The position of the grid cell.
* @param {string} ter - The terrain type of the grid cell.
*/
 Cell::Cell(Position pos, Terrain* ter) {
	this->position = pos;
	this->unit = NULL;
	this->moveCost = 1;
	this->terrain = ter;
	this->groundTraversable = true;
	this->airTraversable = true;
 };

/**
* Puts a Unit into the Cell::Cell.
* @param {Unit} newUnit The Unit to add.
* @return True if the Unit is added, false if impossible.
*/
void Cell::addUnit(Unit* newUnit) {
	this->unit = newUnit;
};

/**
* Remove the Unit from the Cell::Cell.
* @return The Unit removed, false if Cell was empty.
*/
void Cell::removeUnit() {
	this->unit = NULL;
};

/**
* Determines if the Cell has a Unit.
* @return True if occupied, false otherwise.
*/
bool Cell::hasUnit() {
	return this->unit != NULL;
};

/**
* This Cell::Cell's unit
* @name Cell::Cell#unit
* @type Unit
* @default null
*/
Unit* Cell::getUnit() {
	return unit;
}

void Cell::setUnit(Unit* newUnit) {
	this->unit = newUnit;
}

/**
* This Cell::Cell's position
* @name Cell::Cell#position
* @type Position
* @readonly
*/
Position Cell::getPosition() {
	return this->position;
};

/**
* This Cell::Cell's moveCost
* @name Cell::Cell#moveCost
* @type int
* @default 1
* @readonly
*/
int Cell::getMoveCost() {
	return this->moveCost;
};

/**
* If this Cell::Cell is groundTraversable
* @name Cell::Cell#groundTraversable
* @type boolean
* @default true
* @readonly
*/
bool Cell::isGroundTraversable() {
	return this->groundTraversable;
};

/**
* If this Cell::Cell is airTraversable
* @name Cell::Cell#airTraversable
* @type boolean
* @default true
* @readonly
*/
bool Cell::isAirTraversable() {
	return this->airTraversable;
};
