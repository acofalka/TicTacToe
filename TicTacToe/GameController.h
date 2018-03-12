#pragma once

#include "gameEnums.h"
#include "Player.h"
#include "Board.h"
#include "UIController.h"


class GameController
{
private:
	UIController* ui;
	Board* board;
	Player* players[2];
	unsigned currentPlayer;
	unsigned movesDone;
public:
	GameController();
	~GameController();
	void startGame();
	void makeMove();
	bool checkIfWin();
	bool checkIfDraw();
};

