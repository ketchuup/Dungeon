#include "Player.h"

Player::Player() : Creature(getInputName(), 10, 1, 0), level(1) { }

void Player::levelUp()
{
	++level;
	setDamage(getDamage() + 1);
}

bool Player::hasWon()
{
	return (level == 21);
}

int Player::getLevel()
{
	return level;
}

std::string Player::getInputName()
{
	std::string name;
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
	return name;
}
