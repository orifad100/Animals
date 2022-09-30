/*
 * Market.h
 *
 *  Created on: Jan 2, 2022
 *      Author: ise
 */

#ifndef MARKET_H_
#define MARKET_H_
#include "CowFarm.h"
#include "ChickenFarm.h"
#include "SheepFarm.h"
//#include "Exception.h"

class Market
{
private:
	static int years_of_market;
	int sum;
	vector<Farm*> Farms_list;
	vector<Farm*>::iterator it;

public:
	Market();
	void create_new_farm();
	void nextYear();
	void market_day();
	void fastForwardYears();
	void printMarketFarms();

	int getYear();
	virtual ~Market();
};
#endif /* MARKET_H_ */
