#include "Random.h"

void Random::Initialize()
{
	srand(static_cast <unsigned int> (time(0)));
}

int Random::getRandomNumber(int from, int to)
{
	assert(to != from && " 'From' cant be equal 'From'. ");
	return (rand() % to + from);
}
