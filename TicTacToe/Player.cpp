#include "Player.h"

Player::Player(std::string aName, SIGN aSign)
{
	name = aName;
	sign = aSign;
}


Player::~Player() {}

std::string Player::getName()
{
	return name;
}

SIGN Player::getSign()
{
	return sign;
}

