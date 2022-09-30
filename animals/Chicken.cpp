#include "Chicken.h"

Chicken::Chicken(int age, int price, int dead) :Animal(age, price, dead) {}

void Chicken::printInfo()
{
	cout << "Chicken age is: " << get_age() << "\nChicken price is: " << get_price() << "\nChicken will die in is: " << get_dead() << " years old\n";
}

Chicken::~Chicken()
{

}
