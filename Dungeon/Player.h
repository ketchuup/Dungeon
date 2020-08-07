#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Creature.h"

class Player : public Creature
{
	public:
		Player();
		void levelUp();
		bool hasWon();
		int getLevel();
	private:
		int level;
		std::string getInputName();
};

#endif
