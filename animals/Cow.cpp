/*
 * Cow.cpp
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#include "Cow.h"

Cow::Cow(int age, int price, int dead) : Animal(age, price, dead) {};

void  Cow::printInfo()
{
	cout << "Cow age is: " << get_age() << "\nCow price is: " << get_price() << "\nCow will die in is: " << get_dead() << " years old\n";
	//	cout<< "this is cow \n ";
}



//string Cow::FarmwantCows()
//{
//	return "Cow";
//}

Cow::~Cow()
{

}
