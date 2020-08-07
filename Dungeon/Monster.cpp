#include "Monster.h"

Monster::Monster() : Monster(Monster::Type::Slime) { }

Monster::Monster(Type type) :	Creature(	monsterData[type].name,
											monsterData[type].health, 
											monsterData[type].damage, 
											monsterData[type].gold ),
								type(type) { }

Monster::Type Monster::getType()
{
	return type;
}

Monster::MonsterData Monster::monsterData[Type::Quantity] =
{
	// Name,		Health,	Damage,	Gold
	{ "Dragon",		20,		5,		100 },
	{ "Orc",		8,		4,		50 },
	{ "Skeleton",	5,		3,		25 },
	{ "Zombie",		4,		2,		20 },
	{ "Slime",		2,		1,		25 },
	{ "Fairy",		1,		1,		50 }
};