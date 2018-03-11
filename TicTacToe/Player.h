#pragma once
#include "gameEnums.h"
#include <string>

class Player
{
private:
	std::string name;
	SIGN sign;
public:
	Player(std::string, SIGN);
	~Player();
	std::string getName();
	SIGN getSign();
};

