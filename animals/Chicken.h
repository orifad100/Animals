/*
 * Chicken.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#ifndef CHICKEN_H_
#define CHICKEN_H_
#include "Animal.h"

class Chicken : public Animal
{
public:
	Chicken(int age = 0, int price = 3, int dead = 3);
	void printInfo();
	virtual ~Chicken();
};

#endif /* CHICKEN_H_ */
