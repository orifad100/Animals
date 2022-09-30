/*
 * Cow.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#ifndef COW_H_
#define COW_H_
#include "Animal.h"

class Cow : public Animal
{
public:
	Cow(int age = 0, int price = 10, int dead = 10);
	void printInfo();

	virtual ~Cow();
};

#endif /* COW_H_ */
