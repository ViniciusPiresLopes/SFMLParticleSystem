/*
 * Random.h
 *
 *  Created on: 27/06/2020
 *      Author: vinicius
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <iostream>
#include <limits>
#include <stdlib.h>
#include <time.h>

class Random
{
public:
	static void init();
	static float randf();
};

#endif /* RANDOM_H_ */
