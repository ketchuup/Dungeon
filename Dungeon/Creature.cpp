#include "Creature.h"

Creature::Creature(std::string name, int health, int damage, int gold) : name(name), health(health), damage(damage), gold(gold) { }

std::string Creature::getName()
{
	return name;
}

int Creature::getHealth()
{
	return health;
}

int Creature::getDamage()
{
	return damage;
}

int Creature::getGold()
{
	return gold;
}

void Creature::reduceHealth(int damage)
{
	health -= damage;
	health = (health < 0) ? 0 : health;
}

bool Creature::isDead()
{
	return (health == 0);
}

void Creature::addGold(int gold)
{
	this->gold += gold;
}

void Creature::setDamage(int damage)
{
	this->damage = damage;
}
