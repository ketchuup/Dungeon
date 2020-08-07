#ifndef CREARTURE_H
#define CREARTURE_H

#include <string>

class Creature
{
	public:
		Creature(std::string name, int health, int damage, int gold);
		std::string getName();
		int getHealth();
		int getDamage();
		int getGold();
		void reduceHealth(int damage);
		bool isDead();
		void addGold(int gold);
	protected:
		void setDamage(int damage);
	private:
		std::string name;
		int health;
		int damage;
		int gold;
};

#endif
