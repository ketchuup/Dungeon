#include "Game.h"

Game::Game()
{
	monsters.reserve(5);

	printGreeting();

	while (true)
	{
		if (player.hasWon())
		{
			playerWon();
			break;
		}

		showLevel();
		generateMonsters();
		
		do
		{
			printMonsters();
			printPlayerStatistic();
			if (monsters.size())
			{
				processTask(getTask());
			}
			else
			{
				readKey();
				clear();
			}

			if (player.isDead())
			{
				printDeadMessage();
				break;
			}
		} while (monsters.size());

		if (player.isDead())
		{
			break;
		}

		endLevel();
	}
}

void Game::newLine()
{
	std::cout << std::endl;
}

void Game::breakLine()
{
	for (int width = 0; width < 80; ++width)
	{
		std::cout << '=';
	}
	newLine();
}

void Game::clear()
{
	system("cls");
}

void Game::readKey()
{
	std::string tempString;
	std::getline(std::cin, tempString);
}

void Game::playerWon()
{
	std::cout << "[Dungeon is over]" << std::endl;
	std::cout << "You won and collected " << player.getGold() << " gold!" << std::endl;
	readKey();
	newLine();
}

void Game::printGreeting()
{
	newLine();
	clear();
	std::cout << "Welcome, " << player.getName() << '!' << std::endl;
	std::cout << "You entered the dungeon..." << std::endl;
	newLine();
}

void Game::showLevel()
{
	std::cout << "[Dungeon level: " << player.getLevel() << ']' << std::endl;
	newLine();
}

void Game::generateMonsters()
{
	monsters.resize(Random::getRandomNumber(0, 4));
	for (int index = 0; index < monsters.size(); ++index)
	{
		monsters[index] = MonsterFactory::createRandomMonster();
	}
}

void Game::printMonsters()
{
	breakLine();
	if (monsters.size() == 0)
	{
		std::cout << "No monsters \1" << std::endl;
	}
	else
	{
		for (int index = 0; index < monsters.size(); ++index)
			{
				std::cout << '[' << index + 1 << "] " << monsters[index].getName() << ' ' << monsters[index].getHealth() << '/' << Monster::monsterData[static_cast <int> (monsters[index].getType())].health << std::endl;
			}
	}
}

void Game::endLevel()
{
	std::cout << "Going deeper..." << std::endl;
	newLine();
	player.levelUp();
}

void Game::printDeadMessage()
{
	clear();
	std::cout << "You died..." << std::endl;
	std::cout << "You collected " << player.getGold() << " gold..." << std::endl;
	readKey();
}

void Game::printPlayerStatistic()
{
	breakLine();
	std::cout << '[' << player.getName() << "][Health: " << player.getHealth() << "/10][Damage: " << player.getDamage() << "][Gold: " << player.getGold() << "][Level: " << player.getLevel() << ']' << std::endl;
}

Game::Task Game::getTask()
{
	breakLine();
	std::cout << "[1][Fight\t]" << std::endl;
	std::cout << "[2][Run\t\t]" << std::endl;
	std::cout << "[3][Dance\t]" << std::endl;
	std::cout << "[4][Exit\t]" << std::endl;
	std::cout << "~Enter a task: ";

	std::string stringTask;
	std::getline(std::cin, stringTask);

	Task task;
	size_t spacePositon = stringTask.find(' ');
	if (spacePositon != std::string::npos)
	{
		task.command = stringTask.substr(0, spacePositon);
		task.parametrs = stringTask.substr(spacePositon + 1, stringTask.size());
	}
	else
	{
		task.command = stringTask;
		task.parametrs = "";
	}

	std::for_each(	task.command.begin(),
					task.command.end(), 
					[](char &letter) -> void
					{
						letter = ::tolower(letter);
					} );

	std::for_each(	task.parametrs.begin(),
					task.parametrs.end(), 
					[](char &letter) -> void
					{
						letter = ::tolower(letter);
					} );

	return task;
}

void Game::processTask(Task task)
{
	clear();
	if ((task.command == "fight") || (task.command == "1"))
	{
		if (task.parametrs.size())
		{
			fight(task.parametrs);
		}
		else
		{
			std::cout << "No parametrs. Check tutorial for help." << std::endl;
		}
	}
	else if ((task.command == "run") || (task.command == "2"))
	{
		if (!task.parametrs.size())
		{
			run();
		}
		else
		{
			std::cout << "Parameters passed. Check tutorial for help." << std::endl;
		}
	}
	else if ((task.command == "dance") || (task.command == "3"))
	{
		if (!task.parametrs.size())
		{
			dance();
		}
		else
		{
			std::cout << "Parameters passed. Check tutorial for help." << std::endl;
		}
	}
	else if ((task.command == "exit") || (task.command == "4"))
	{
		if (!task.parametrs.size())
		{
			exitDungeon();
		}
		else
		{
			std::cout << "Parameters passed. Check tutorial for help." << std::endl;
		}
	}
	else
	{
		std::cout << "Unknown task!" << std::endl;
	}
	newLine();
}

void Game::fight(std::string target)
{
	int monsterID = std::stoi(target) - 1;
	monsters[monsterID].reduceHealth(player.getDamage());
	std::cout << "You attacked " << monsters[monsterID].getName() << " (" << monsterID + 1 << ')' << std::endl;
	if (monsters[monsterID].isDead())
	{
		player.addGold(monsters[monsterID].getGold());
		std::cout << monsters[monsterID].getName() << " (" << monsterID + 1 << ')' << " died." << std::endl;
		monsters.erase(monsters.begin() + monsterID);
	}
	else
	{
		player.reduceHealth(monsters[monsterID].getDamage());
		std::cout << "You was attacked by " << monsters[monsterID].getName() << " (" << monsterID << ')' << std::endl;
	}
}

void Game::run()
{
	int successRun = Random::getRandomNumber(1, 5);
	if (successRun == 1)
	{
		std::cout << "Running away..." << std::endl;
		if (player.getGold())
		{
			int lostGold = Random::getRandomNumber(0, player.getGold() / 3);
			if (lostGold)
			{
				std::cout << "When you ran away you lost some gold: " << lostGold << '!' << std::endl;
				player.addGold(-lostGold);
			}
		}
		monsters.resize(0);
	}
	else
	{
		std::cout << "Unsuccessful attempt to escape!" << std::endl;
		int monsterID = Random::getRandomNumber(0, static_cast <int> (monsters.size()));
		std::cout << monsters[monsterID].getName() << " (" << monsterID + 1 << ')' << " caught you and attacked!" << std::endl;
		player.reduceHealth(monsters[monsterID].getDamage());
	}
}

void Game::dance()
{
	std::cout << "You danced :/" << std::endl;
	if (monsters.size())
	{
		int monsterID = Random::getRandomNumber(0, static_cast <int> (monsters.size()));
		std::cout << monsters[monsterID].getName() << " (" << monsterID + 1 << ')' << " didn't like it!" << std::endl;
		player.reduceHealth(monsters[monsterID].getDamage());
		std::cout << "You was attacked by " << monsters[monsterID].getName() << " (" << monsterID + 1 << ')' << std::endl;
		newLine();
	}
}

void Game::exitDungeon()
{
	player.reduceHealth(player.getHealth());
	std::cout << "Bye, " << player.getName() << '!' << std::endl;
	readKey();
}
