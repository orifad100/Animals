/*
 * Animal.h
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <iostream>
using namespace std;

class Animal
{
protected:
	int m_age;
	int m_price;
	int m_dead;
public:
	Animal(int a, int p, int d);
	virtual void printInfo() = 0;

	void set_age(int);
	void set_price(int);
	void set_dead(int);
	int get_age() const;
	int get_price() const;
	int get_dead()const;
	virtual ~Animal();
};

#endif /* ANIMAL_H_ */
