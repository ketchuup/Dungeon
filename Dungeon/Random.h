#ifndef RANDOM_H
#define RANDOM_H

#include <cassert>
#include <cstdlib>
#include <ctime>

class Random
{
	public:
		Random() = delete;
		static void Initialize();
		static int getRandomNumber(int from, int to);
};

#endif