#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H

#include "Monster.h"
#include "Random.h"

class MonsterFactory
{
	public:
		MonsterFactory() = delete;
		static Monster createRandomMonster();
};

#endif