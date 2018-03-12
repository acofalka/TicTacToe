#include "UIController.h"
#include <iostream>
using namespace std;


UIController::UIController() {}

UIController::~UIController() {}

string* UIController::getPlayersNames()
{
	string* names = new string[2];
	cout << "Podaj imie 1. gracza: ";
	cin >> names[0];
	cout << "Podaj imie 2. gracza: ";
	cin >> names[1];
	return names;
}

void UIController::printBoard(Board* board) 
{
	system("cls");
	cout << "      Kolko i krzyzyk          " << endl << endl;
	cout << "          -----" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "          |";
		for (int j = 0; j < 3; j++) {
			int fieldNo = 3 * i + j + 1;
			switch (board->getField(i, j)) {
			case F_EMPTY:
				cout << fieldNo;
				break;
			case F_CIRCLE:
				cout << "O";
				break;
			case F_CROSS:
				cout << "X";
				break;
			default:
				break;
			}
		}
		cout << "|" << endl;
	}
	cout << "          -----" << endl << endl;
}

int UIController::getFieldToOccupy(Player* player)
{
	int chosenField;
	cout << "Kolej gracza " << player->getName() << " (";
	cout << (player->getSign() == F_CIRCLE ? "kolka" : "krzyzyki");
	cout << ")" << endl;
	cout << "Wybierz nr pola (1-9): ";
	while (!(cin >> chosenField) || chosenField < 1 || chosenField > 9) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Nieprawidlowy ruch. Wybierz nr pola (1-9): ";
	}
	return chosenField;
}

int UIController::getFieldAfterChoosingOccupied(Player* player)
{
	cout << "Wybrales pole, ktore jest juz zajete. Wybierz inne pole." << endl;
	getFieldToOccupy(player);
	return 0;
}

void UIController::printWin(Player* player)
{
	cout << "Wygral gracz " << player->getName() << "!" << endl;
}

void UIController::printDraw()
{
	cout << "Koniec gry. Remis!" << endl;
}