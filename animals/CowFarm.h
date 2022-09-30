/*
 * CowFarm.h
 *
 *  Created on: Jan 2, 2022
 *      Author: ise
 */

#ifndef COWFARM_H_
#define COWFARM_H_
#include"Farm.h"

class CowFarm : public Farm
{
protected:



public:
	CowFarm();
	virtual void output_farm();
	virtual void buy_products(Farm* F);
	virtual void buy_animals();
	virtual void print_farm();
	void get_old();
	int get_id();
	//void delet_cow(Animal * c);

	virtual void cow_farm_handel();
	virtual void sheep_farm_handel(){};
	virtual void chicken_farm_handel(){};

	virtual void cow_farm_market( );
	virtual void sheep_farm_market( ){};
	virtual void chicken_farm_market(){};

	virtual void client_is_sheepfarm(Farm* F);
	virtual void client_is_cowfarm(Farm*){};
	virtual void client_is_chickenfarm(Farm*){};

	virtual bool add_sheepfarm_to_cowfarm(){return false;};
	virtual bool add_cowfarm_to_chickenfarm();
	virtual bool add_chickenfarm_to_sheepfarm(){return false;};




	virtual ~CowFarm();
};
#endif /* COWFARM_H_ */
