#include "Farm.h"

int Farm::serial = 1;

Farm::Farm()
{
	ID = serial;
	number_animals = 3;
	Money = 10;
	number_products_buy = 0;
	number_product_sell = 0;
	serial++;


}

int Farm::get_product_sell()
{
	return this->number_product_sell;
}

void Farm::set_product_sell(int number)
{
	this->number_product_sell = number;
}

void Farm::set_money(int number)
{
	this->Money=this->Money+number;
}

Farm::~Farm()
{
	for ( it = animals.begin(); it != animals.end(); )
	{
		delete * it;
		 it = animals.erase(it);
	}


	animals.clear();
	animals.shrink_to_fit();


}
