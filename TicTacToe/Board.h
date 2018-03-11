#pragma once

#include "gameEnums.h"

class Board
{
private:
	FIELD board[3][3];
public:
	Board();
	~Board();
	FIELD getField(unsigned, unsigned);
	void setField(unsigned, unsigned, SIGN sign);
	bool isOccupied(unsigned, unsigned);
	bool winCheck();
	bool drawCheck();
};

