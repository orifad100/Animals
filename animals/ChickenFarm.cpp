/*
 * ChickenFarm.cpp
 *
 *  Created on: Jan 2, 2022
 *      Author: ise
 */

#include "ChickenFarm.h"
#include <algorithm>
ChickenFarm::ChickenFarm() : Farm()
{
	for (int i = 0; i < this->number_animals; i++)
	{
		Chicken* s = new Chicken(0, 3, 3);
		animals.push_back(s);
	}
}

int ChickenFarm::get_id()
{
	return this->ID;

}


void ChickenFarm::get_old()
{
	//this->output_farm();
	int age=0;
	for (int i = 0; i < this->number_animals; i++)
	{
		age = animals[i]->get_age();
		age++;
		animals[i]->set_age(age);
	}
	for (int i = 0; i < this->number_animals; i++)
	{
		if(animals[i]->get_age()==3)
		{
			delete animals[i];
			this->number_animals--;
			animals.erase(animals.begin()+i);
			i--;
		}
	}
	//this->output_farm();
}
void ChickenFarm::output_farm()
{
	int save_out;
	save_out=this->number_product_sell;
	int counter = 0;
	for (int i = 0; i < this->number_animals; i++)
		counter +=animals[i]->get_age();
	this->number_product_sell = counter+save_out;
}

void ChickenFarm::buy_products(Farm* F)
{
	int number;
	int count=0;
	while (F->get_product_sell() > 0)
	{
		if(Money>=2)
		{
			Money = Money - 2;
			F->set_money(2);
			number = F->get_product_sell();
			count++;
			number--;
			F->set_product_sell(number);
			this->number_products_buy++;
		}
		else
			break;
	}
	if(count>0)
		cout<<"Chicken farm("<<this->ID<<") bought "<<count<<" wool for "<<count*2<<" dollars from Sheep farm("<<F->get_id()<<")"<<"\n";
}

void ChickenFarm::buy_animals()
{
	while (Money > 5)
	{
		this->number_animals++;
		Chicken* s = new Chicken(0, 3, 3);
		animals.push_back(s);
		Money = Money - 5;
	}
}

void ChickenFarm::print_farm()
{
	//this->output_farm();
	cout << "Farm Id: " << this->ID << ", type: Chicken Farm, Money: " << this->Money << ", Animals: " << this->number_animals << " chickens, Products: ";
	cout << "Milk[0], Wool[" << this->number_products_buy << "], Eggs[" << this->number_product_sell << "]\n";
}

void ChickenFarm::chicken_farm_handel()
{

	while(this->Money>=3)
	{
		Animal * A =new Chicken(0,3,3);
		Money=Money-3;
		animals.push_back(A);
		this->number_animals++;


	}

}

void ChickenFarm::chicken_farm_market()
{
	if(this->Money>=3)
	{
		int number_chieckens, money_spend;
		number_chieckens=this->Money/3;
		money_spend=3*number_chieckens;
		cout<<"Chicken farm("<<this->ID<<") bought "<<number_chieckens<<" chickens for "<< money_spend<< " dollars"<<"\n";
	}

}


void ChickenFarm::client_is_cowfarm(Farm*F)
{
	if(F->add_cowfarm_to_chickenfarm()==true)
	{
		if(count(this->list_of_client.begin(), list_of_client.end(), F))
		{

		}
		else
		{
			this->list_of_client.push_back(F);
			cout<<"Chicken farm("<<this->ID<<") Added Cow farm("<<F->get_id()<<") to his client list"<<"\n";
		}

	}


}

bool ChickenFarm::add_chickenfarm_to_sheepfarm()
{
	return true;


}

ChickenFarm::~ChickenFarm()
{
//	int i;
//		for(i=0;i<this->list_of_client.size();i++)
//		{
//			delete this->list_of_client[i];
//			list_of_client.erase(list_of_client.begin()+i);
//		}
//		this->list_of_client.clear();


}
