#pragma once
class Cell
{
	Position position;
	Terrain* terrain;
	Unit* unit;
	int moveCost;
	bool groundTraversable;
	bool airTraversable;
public:
	Cell(Position pos, Terrain* ter);
	void addUnit(Unit* newUnit);
	void removeUnit();
	bool hasUnit();
	Unit* getUnit();
	void setUnit(Unit* newUnit);
	Position getPosition();
	int getMoveCost();
	bool isGroundTraversable();
	bool isAirTraversable();

	~Cell();
};

