#include "GameController.h"
#include "gameEnums.h"
#include <conio.h>

void main()
{
	GameController controller;
	controller.startGame();
	while (true) {
		controller.makeMove();
		if (controller.checkIfWin()) break;
		else if (controller.checkIfDraw()) break;
	}
	_getch();
}