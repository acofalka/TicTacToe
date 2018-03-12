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
	currentPlayer = -1;
	movesDone = 0;
}


GameController::~GameController()
{
	delete ui;
	delete board;
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

bool GameController::checkIfDraw()
{
	bool isBoardFull = (movesDone == MAXMOVES);
	if (isBoardFull)
	{
		ui->printBoard(board);
		ui->printDraw();
	}
	return isBoardFull;
}

bool GameController::checkIfWin()
{
	bool win = board->checkIfWin();
	if (win)
	{
		ui->printBoard(board);
		ui->printWin(players[currentPlayer]);
	}
	else
		currentPlayer = 1 - currentPlayer;
	return win;
}

void GameController::makeMove()
{
	ui->printBoard(board);
	int toOccupy = 0;
	toOccupy = ui->getFieldToOccupy(players[currentPlayer]);
	while (board->isOccupied(toOccupy))
		toOccupy = ui->getFieldAfterChoosingOccupied(players[currentPlayer]);
	SIGN sign = players[currentPlayer]->getSign();
	board->setField(toOccupy, sign);
	movesDone++;
}