#ifndef MENU_H
#define MENU_H

#include "Game.h"

class Menu
{
	public:
		Menu();
	private:
		void printTitle();
		void printMenu();
		std::string getInput();
		bool processInput(std::string input);
};

#endif