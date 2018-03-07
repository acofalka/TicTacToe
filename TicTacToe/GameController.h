#pragma once

#include "gameEnums.h"
#include "Player.h"


class GameController
{
private:
	GAMESTATE gameState;
	Player* players[2];
	unsigned currentPlayer;
public:
	GameController();
	~GameController();
	void startGame();
};

