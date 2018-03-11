#include "GameController.h"
#include <ctime>
#include <string>
using namespace std;

GameController::GameController()
{
	for (int i = 0; i < 2; i++)
		players[i] = NULL;
	board = new Board;
	ui = new UIController;
}


GameController::~GameController()
{
	for (int i = 0; i < 2; i++)
		delete players[i];
}

void GameController::startGame()
{
	srand(static_cast<unsigned>(time(NULL)));
	string* names = ui->getPlayersNames();
	currentPlayer = rand() % 2;
	players[currentPlayer] = new Player(names[currentPlayer], S_CROSS);
	int notCurrent = 1 - currentPlayer;
	players[notCurrent] = new Player(names[notCurrent], S_CIRCLE);
}
