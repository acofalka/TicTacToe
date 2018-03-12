#include "GameController.h"
#include "gameEnums.h"
#include <conio.h>

void main()
{
	GameController controller;
	controller.startGame();
	bool inGame = true;
	while (inGame) {
		controller.makeMove();
		if (controller.checkIfWin() || controller.checkIfDraw())
			inGame = false;
	}
	_getch();
}