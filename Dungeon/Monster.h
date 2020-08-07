#ifndef MONSTER_H
#define MONSTER_H

#include "Creature.h"

class Monster : public Creature
{
	private:

		enum Type
		{
			Dragon,
			Orc,
			Skeleton,
			Zombie,
			Slime,
			Fairy,
			Quantity
		};

		struct MonsterData
		{
			std::string name;
			int health;
			int damage;
			int gold;
		};

		static MonsterData monsterData[];
		Type type;

		friend class MonsterFactory;
		friend class Game;

	public:
		Monster();
		Monster(Type type);
		Type getType();
};

#endif