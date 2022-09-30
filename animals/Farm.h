/*
 * Farm.h
 *
 *  Created on: Dec 31, 2021
 *      Author: ise
 */

#ifndef FARM_H_
#define FARM_H_
#include<vector>
#include"Animal.h"
#include "Chicken.h"
#include "Cow.h"
#include "Sheep.h"

#define SIZE 3

class Farm
{
protected:
	int ID;
	int number_animals;
	int Money;
	int number_products_buy;
	int number_product_sell;
	vector<Animal*>animals;
	vector<Farm*>list_of_client;
	vector<Animal*>::iterator it;
	//int products[SIZE];
	static int serial;
public:
	Farm();
	virtual void output_farm() = 0;
	virtual void buy_products(Farm* F) = 0;
	virtual void buy_animals() = 0;
	virtual void print_farm() = 0;
	virtual void get_old() = 0;
	virtual int get_id()=0;

	int get_product_sell();
	void set_product_sell(int number);
	void set_money(int num);

	virtual void cow_farm_handel( )=0;
	virtual void sheep_farm_handel()=0;
	virtual void chicken_farm_handel()=0;

	virtual void cow_farm_market( )=0;
	virtual void sheep_farm_market( )=0;
	virtual void chicken_farm_market()=0;

	virtual void client_is_sheepfarm(Farm*)=0;
	virtual void client_is_cowfarm(Farm*)=0;
	virtual void client_is_chickenfarm(Farm*)=0;

	virtual bool add_sheepfarm_to_cowfarm()=0;
	virtual bool add_cowfarm_to_chickenfarm()=0;
	virtual bool add_chickenfarm_to_sheepfarm()=0;

	friend class Market;
	virtual ~Farm();
};
#endif /* FARM_H_ */
