/*
 * CowFarm.cpp
 *
 *  Created on: Jan 2, 2022
 *      Author: ise
 */

#include "CowFarm.h"
#include <algorithm>

CowFarm::CowFarm() : Farm()
{
	for (int i = 0; i < this->number_animals; i++)
	{
		Cow* c = new Cow(0, 10, 10);
		animals.push_back(c);
	}
}

int CowFarm::get_id()
{
	return this->ID;

}

void CowFarm::output_farm()
{
	int save_out;
	save_out=this->number_product_sell;
	int counter = 0;
	for (int i = 0; i < this->number_animals; i++)
		counter += animals[i]->get_age();
	this->number_product_sell = counter+save_out;
}

//void CowFarm::delet_cow(Animal *c)
//{
//	delete c;
//}

void CowFarm::get_old()
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
		if(animals[i]->get_age()==10)
		{
			delete animals[i];
			this->number_animals--;
			animals.erase(animals.begin()+i);
			i--;
		}
	}

}

void CowFarm::buy_products(Farm* F)
{
	int number;
	int count=0;

	while (F->get_product_sell() >0 )
	{
		if(Money >=1)
		{

			Money--;
			F->set_money(1);
			number = F->get_product_sell();
			number--;
			F->set_product_sell(number);
			count++;
			this->number_products_buy++;
		}
		else
			break;

	}
	if(count>0)
		cout<<"Cow farm("<<this->ID<<") bought "<<count<<" eggs for "<<count<<" dollars from Chicken farm("<<F->get_id()<<")"<<"\n";
}

void CowFarm::buy_animals()
{
	while (Money > 10)
	{
		this->number_animals++;
		Cow* c = new Cow(0, 10, 10);
		animals.push_back(c);
		Money -= 10;
	}
}

void CowFarm::print_farm()
{
	//this->output_farm();
	cout << "Farm Id: " << this->ID << ", type: Cow farm, Money: " << this->Money << ", Animals: " << this->number_animals << " cows, Products: ";
	cout << "Milk[" << this->number_product_sell << "], Wool[0], Eggs[" << this->number_products_buy << "]\n";
}

void CowFarm::cow_farm_handel()
{

	while(this->Money>=10)
	{
		Cow * A =new Cow(0,10,10);
		Money=Money-10;
		animals.push_back(A);
		this->number_animals++;


	}

}

void CowFarm::cow_farm_market()
{
	if(this->Money>=10)
	{
		int number_cows, money_spend;
		number_cows=this->Money/10;
		money_spend=10*number_cows;
		cout<<"Cow farm("<<this->ID<<") bought "<<number_cows<<" cows for "<< money_spend<< " dollars"<<"\n";
	}

}

void CowFarm::client_is_sheepfarm(Farm * F)
{
	if(F->add_sheepfarm_to_cowfarm()==true)
	{
		if(count(this->list_of_client.begin(), list_of_client.end(), F))
		{

		}
		else
		{
			this->list_of_client.push_back(F);
			cout<<"Cow farm("<<this->ID<<") Added Sheep farm("<<F->get_id()<<") to his client list"<<"\n";
		}



	}

}

bool CowFarm::add_cowfarm_to_chickenfarm()
{
	return true;


}

CowFarm::~CowFarm() 
{
//	int i;
//		for(i=0;i<this->list_of_client.size();i++)
//		{
//			delete this->list_of_client[i];
//			list_of_client.erase(list_of_client.begin()+i);
//		}
//		this->list_of_client.clear();

}
