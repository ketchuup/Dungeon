#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "MonsterFactory.h"
#include <vector>
#include <algorithm>

class Game
{
	private:
		struct Task
		{
			std::string command;
			std::string parametrs;
		};
		Player player;
		std::vector <Monster> monsters;
	public:
		Game();
	private:

		// Working with console
		void newLine();
		void breakLine();
		void clear();
		void readKey();

		// Other
		void playerWon();
		void printGreeting();
		void showLevel();
		void generateMonsters();
		void printMonsters();
		void endLevel();
		void printDeadMessage();
		void printPlayerStatistic();

		// Working with tasks
		Task getTask();
		void processTask(Task task);

		// Execute task
		void fight(std::string target);
		void run();
		void dance();
		void exitDungeon();
};

#endif