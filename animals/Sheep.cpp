#include "Sheep.h"

Sheep::Sheep(int age, int price, int dead) :Animal(age, price, dead) {}

void Sheep::printInfo()
{
	cout << "Sheep age is: " << get_age() << "\nSheep price is: " << get_price() << "\nSheep will die in is: " << get_dead() << " years old\n";
}

Sheep::~Sheep()
{

}
