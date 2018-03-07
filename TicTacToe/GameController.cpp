#include "GameController.h"


GameController::GameController()
{
	gameState = NOTSTARTED;
	for (int i = 0; i < 2; i++)
		players[i] = NULL;
}


GameController::~GameController()
{
	for (int i = 0; i < 2; i++)
		delete players[i];
}

void GameController::startGame()
{

}
