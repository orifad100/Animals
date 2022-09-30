/*
 * Sheep.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#ifndef SHEEP_H_
#define SHEEP_H_
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(int age = 0, int price = 5, int dead = 5);
	void printInfo();
	virtual ~Sheep();
};
#endif /* SHEEP_H_ */
