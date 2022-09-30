/*
 * SheepFarm.h
 *
 *  Created on: Jan 2, 2022
 *      Author: ise
 */

#ifndef SHEEPFARM_H_
#define SHEEPFARM_H_
#include "Farm.h"

class SheepFarm : public Farm
{
protected:


public:
	SheepFarm();
	int get_id();
	virtual void output_farm();
	virtual void buy_products(Farm* F);
	virtual void buy_animals();
	virtual void print_farm();
	virtual void get_old();

	virtual void cow_farm_handel(){};
	virtual void sheep_farm_handel();
	virtual void chicken_farm_handel(){};

	virtual void cow_farm_market(){};
	virtual void sheep_farm_market();
	virtual void chicken_farm_market(){};

	virtual void client_is_sheepfarm(Farm*){};
	virtual void client_is_cowfarm(Farm*){};
	virtual void client_is_chickenfarm(Farm*);

	virtual bool add_sheepfarm_to_cowfarm();
	virtual bool add_cowfarm_to_chickenfarm(){return false;};
	virtual bool add_chickenfarm_to_sheepfarm(){return false;};




	//	virtual string handelCowsFarm(Animal* A){return A->FarmwantCows();};
	//	virtual void handelSheepsFarm(Animal*);
	//	virtual void handelChickensFarm(Animal*);
	virtual ~SheepFarm();
};
#endif /* SHEEPFARM_H_ */
