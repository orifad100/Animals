/*
 * ChickenFarm.h
 *
 *  Created on: Jan 2, 2022
 *      Author: ise
 */

#ifndef CHICKENFARM_H_
#define CHICKENFARM_H_
#include "Farm.h"

class ChickenFarm : public Farm
{
protected:


public:
	ChickenFarm();
	virtual void output_farm();
	virtual void buy_products(Farm* F);
	virtual void buy_animals();
	virtual void print_farm();
	int get_id();
	void get_old();


	virtual void cow_farm_handel(){};
	virtual void sheep_farm_handel( ){};
	virtual void chicken_farm_handel();

	virtual void cow_farm_market(){};
	virtual void sheep_farm_market( ){};
	virtual void chicken_farm_market();

	virtual void client_is_sheepfarm(Farm*){};
	virtual void client_is_cowfarm(Farm*F);
	virtual void client_is_chickenfarm(Farm*){};

	virtual bool add_sheepfarm_to_cowfarm(){return false;};
	virtual bool add_cowfarm_to_chickenfarm(){return false;};
	virtual bool add_chickenfarm_to_sheepfarm();
	virtual ~ChickenFarm();


	//friend class CowFarm;
};

#endif /* CHICKENFARM_H_ */
