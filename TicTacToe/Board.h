#pragma once

#include "gameEnums.h"

class Board
{
private:
	FIELD board[3][3];
	int convertX(int);
	int convertY(int);
public:
	Board();
	~Board();
	FIELD getField(unsigned, unsigned);
	void setField(unsigned, SIGN sign);
	bool isOccupied(unsigned);
	bool checkIfWin();
};

