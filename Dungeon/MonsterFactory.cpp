#include "MonsterFactory.h"

Monster MonsterFactory::createRandomMonster()
{
	return Monster(static_cast <Monster::Type> (Random::getRandomNumber(0, Monster::Type::Quantity)));
}
