#pragma once

#include "Board.h"
#include "Player.h"
#include <string>

class UIController
{
public:
	UIController();
	~UIController();
	std::string* getPlayersNames();
	void printBoard(Board*);
	int getFieldToOccupy(Player*);
	int getFieldAfterChoosingOccupied(Player*);
	void printWin(Player*);
	void printDraw();
};
