/*
 * SheepFarm.cpp
 *
 *  Created on: Jan 2, 2022
 *      Author: ise
 */

#include "SheepFarm.h"
#include <algorithm>

SheepFarm::SheepFarm() : Farm()
{
	for (int i = 0; i < this->number_animals; i++)
	{
		Sheep* s = new Sheep(0, 5, 5);
		animals.push_back(s);
	}
}

int SheepFarm::get_id()
{
	return this->ID;

}
void SheepFarm::output_farm()
{
	int save_out;
	save_out=this->number_product_sell;
	int counter = 0;
	for (int i = 0; i < this->number_animals; i++)
		counter += animals[i]->get_age();
	this->number_product_sell = counter+save_out;
}

void SheepFarm::buy_products(Farm* F)
{
	int number;
	int count=0;
	while (F->get_product_sell() > 0 )
	{
		if(Money >= 3)
		{
			Money = Money - 3;
			F->set_money(3);
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
		cout<<"Sheep farm("<<this->ID<<") bought "<<count<<" milk for "<<count*3<<" dollars from Cow farm("<<F->get_id()<<")"<<"\n";
}

void SheepFarm::get_old()
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
			if(animals[i]->get_age()==5)
			{
				delete animals[i];
				this->number_animals--;
				animals.erase(animals.begin()+i);
				i--;
			}
		}
	//this->output_farm();
}

void SheepFarm::buy_animals()
{
	while (Money > 5)
	{
		this->number_animals++;
		Sheep* s = new Sheep(0, 5, 5);
		animals.push_back(s);
		Money = Money - 5;
	}
}

void SheepFarm::print_farm()
{
	//this->output_farm();
	cout << "Farm Id: " << this->ID << ", type: Sheep farm, Money: " << this->Money << ", Animals: " << this->number_animals << " sheep, Products: ";
	cout << "Milk[" << this->number_products_buy << "], Wool[" << this->number_product_sell << "], Eggs[0]\n";
}

void SheepFarm::sheep_farm_handel()
{

	while(this->Money>=5)
	{
		Animal * A =new Sheep(0,5,5);
		Money=Money-5;
		animals.push_back(A);
		this->number_animals++;


	}

}

void SheepFarm::sheep_farm_market()
{
	if(this->Money>=5)
	{
		int i;
		int number_sheep, money_spend;
		number_sheep=this->Money/5;
		money_spend=5*number_sheep;

		cout<<"Sheep farm("<<this->ID<<") bought "<<number_sheep<<" sheeps for "<< money_spend<< " dollars"<<"\n";

	}

}


void SheepFarm::client_is_chickenfarm(Farm* F)
{
	if(F->add_chickenfarm_to_sheepfarm()==true)
	{
		if(count(this->list_of_client.begin(), list_of_client.end(), F))
		{

		}
		else
		{
			this->list_of_client.push_back(F);
			cout<<"Sheep farm("<<this->ID<<") Added Chicken farm("<<F->get_id()<<") to his client list"<<"\n";
		}




	}

}
bool SheepFarm::add_sheepfarm_to_cowfarm()
{
	return true;
}

SheepFarm::~SheepFarm()
{
//	int i;
//	for(i=0;i<this->list_of_client.size();i++)
//	{
//		delete this->list_of_client[i];
//		list_of_client.erase(list_of_client.begin()+i);
//	}
//	this->list_of_client.clear();

}
