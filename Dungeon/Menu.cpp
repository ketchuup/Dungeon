#include "Menu.h"

Menu::Menu()
{
	bool run = true;
	printTitle();
	while (run)
	{
		printMenu();
		run = processInput(getInput());
	}
}

void Menu::printTitle()
{
	std::cout << "Dungeon v.1" << std::endl << std::endl;
}

void Menu::printMenu()
{
	std::cout << "[1][Play\t]" << std::endl;
	std::cout << "[2][Tutorial\t]" << std::endl;
	std::cout << "[3][About\t]" << std::endl;
	std::cout << "[4][Exit\t]" << std::endl;
}

std::string Menu::getInput()
{
	std::cout << "> ";
	std::string input;
	std::getline(std::cin, input);
	return input;
}

bool Menu::processInput(std::string input)
{
	system("cls");
	if ((input == "play") || (input == "1"))
	{
		Game();
	}
	else if ((input == "tutorial") || (input == "2"))
	{
		std::cout << R"(
The goal of the game is to go through 20 floors of the dungeon and collect as much as possible amount of gold.

During the game, you will have 4 commands available:
	-Fight (Attack monster)
	-Run (Try to escape)
	-Dance (Dance and skip a move)
	-Exit (Exit the dungeon)
You can call them through a code or name (As you like).
For example: you have command [2][Run] and you can call it with "Run" or "2".

Commands have parameters:
	-Fight <Target>
	-Run <None>
	-Dance <None>
	-Exit <None>
Here <None> denotes the absence of parameters, and <Target> for the "Fight" command denotes the target of the attack.
They must be entered after a space after the command.
For example: you have command [1][Fight] and you can call it with "Fight 1" or "1 1". (Here the second 1 is monsterID (This is what kind of monster you want to attack)). [1] Slime 1/1 - this [1] is the monsterID.

Each level your damage will increase by 1.
You will be attacked by monster which was attacked by you.)";
		std::string tempString;
		std::getline(std::cin, tempString);
	}
	else if ((input == "about") || (input == "3"))
	{
		std::cout << "Dungeon v.1 by Ketchuup" << std::endl;
		std::string tempString;
		std::getline(std::cin, tempString);
	}
	else if ((input == "exit") || (input == "4"))
	{
		std::cout << "Bye-bye!" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Unknown command!" << std::endl;
		std::string tempString;
		std::getline(std::cin, tempString);
	}
	system("cls");
	return true;
}
