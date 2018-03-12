#include "Board.h"


Board::Board()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = F_EMPTY;
}


Board::~Board() {}

FIELD Board::getField(unsigned x, unsigned y)
{
	return board[x][y];
}

bool Board::checkIfWin()
{
	for (int i = 0; i < 3; i++) {
		if (board[i][0] != F_EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return true;
		}
		if (board[0][i] != F_EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return true;
		}
	}
	if (board[1][1] != F_EMPTY) {
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			return true;
		}
		else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			return true;
		}
	}
	return false;
}

bool Board::isOccupied(unsigned fieldNo)
{
	int x = convertX(fieldNo);
	int y = convertY(fieldNo);
	if (board[x][y] == F_EMPTY)
		return false;
	else return true;
}

void Board::setField(unsigned fieldNo, SIGN sign)
{
	int x = convertX(fieldNo);
	int y = convertY(fieldNo);
	board[x][y] = static_cast<FIELD>(sign);
}

int Board::convertX(int fieldNo)
{
	return (fieldNo - 1) / 3;
}

int Board::convertY(int fieldNo)
{
	return (fieldNo - 1) % 3;
}