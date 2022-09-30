/*
 * Animal.cpp
 *
 *  Created on: Dec 30, 2021
 *      Author: ise
 */

#include "Animal.h"

Animal::Animal(int a, int p, int d)
{
	set_age(a);
	set_dead(d);
	set_price(p);
}

void Animal::set_age(int age)
{
	this->m_age = age;
}

void Animal::set_price(int price)
{
	this->m_price = price;
}

void Animal::set_dead(int dead)
{
	this->m_dead = dead;
}

int Animal::get_age()const
{
	return this->m_age;
}

int Animal::get_price() const
{
	return this->m_price;
}

int Animal::get_dead()const
{
	return this->m_dead;
}

Animal::~Animal()
{


}
