/*
 * Random.cpp
 *
 *  Created on: 27/06/2020
 *      Author: vinicius
 */

#include "Random.h"

void Random::init()
{
	srand(time(NULL));
}

float Random::randf()
{
	return (float) rand() / (float) std::numeric_limits<int>::max();
}
