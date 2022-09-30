/*
 * Market.cpp
 *
 *  Created on: Jan 2, 2022
 *      Author: ise
 */

#include "Market.h"
#include"Exception.h"
#include <typeinfo>

int Market:: years_of_market=0;

Market::Market()
{
	years_of_market = 0;
	this->sum=0;
}

void Market:: create_new_farm()
{
	int count=0;
	int j;
	int cows_num,sheep_num,chicken_num;

	cout<<"How many new cow farms will be added this year?"<<"\n";
	cin>>cows_num;
	try{
		if(cows_num<0)
			throw Cowexception;

	}
	catch(exception &e)
	{
		cout<<e.what()<<"\n";
		this->create_new_farm();
		return;
	}
	for (int i = 0; i < cows_num; i++)
	{
		CowFarm* A = new CowFarm();
		Farms_list.push_back(A);
	}


	cout<<"How many new sheep farms will be added this year?"<<"\n";
	cin>>sheep_num;
	try{
		if(sheep_num<0)
			{
					throw Sheepexception;

			}

		}
		catch(exception &e)
		{
			cout<<e.what()<<"\n";
			Farms_list[Farms_list.size()]->serial--;
			delete Farms_list[Farms_list.size()-1];
			Farms_list.pop_back();
			this->create_new_farm();
			return;
		}
	for (int i = 0; i < sheep_num; i++)
	{
		SheepFarm* C = new SheepFarm();
		Farms_list.push_back(C);
	}

	cout<<"How many new chicken farms will be added this year?"<<"\n";
	cin>>chicken_num;
	try{
		if(chicken_num<0)
			{
				throw Chickenexception;
			}
		}
		catch(exception &e)
		{
			cout<<e.what()<<"\n";
			Farms_list[Farms_list.size()-1]->serial--;
			Farms_list[Farms_list.size()]->serial--;
			delete Farms_list[Farms_list.size()-2];
			delete Farms_list[Farms_list.size()-1];
			Farms_list.pop_back();
			Farms_list.pop_back();

			this->create_new_farm();
			return;
		}

	for (int i = 0; i < chicken_num; i++)
	{

		ChickenFarm* t = new ChickenFarm();
		Farms_list.push_back(t);
	}
	this->sum=cows_num+sheep_num+chicken_num;
}


void Market::nextYear()
{
	int i;
	cout<<"----Creating new farms----"<<"\n";
	this->create_new_farm();
	for(i=0;i<Farms_list.size();i++)
		Farms_list[i]->output_farm();
	//int i ;
	this->market_day();


	this->years_of_market++;


}

void Market::market_day()
{
	int i,j ;


	if(this->years_of_market==0)
	{
		cout<<"----Adding new farms to market----"<<"\n";

		if(this->sum>0)
		{
			for(i=0;i<Farms_list.size();i++)
			{
				for(j=0;j<i;j++)
				{
					Farms_list[i]->client_is_cowfarm(Farms_list[j]);
					Farms_list[j]->client_is_cowfarm(Farms_list[i]);
					Farms_list[i]->client_is_sheepfarm(Farms_list[j]);
					Farms_list[j]->client_is_sheepfarm(Farms_list[i]);
					Farms_list[i]->client_is_chickenfarm(Farms_list[j]);
					Farms_list[j]->client_is_chickenfarm(Farms_list[i]);
				}
			}
			cout<<"----Begin Market----"<<"\n";
		}

	}


	if(this->years_of_market!=0)
	{
		cout<<"----Adding new farms to market----"<<"\n";
		if(this->sum>0)
		{
			for(i=0;i<Farms_list.size();i++)
			{
				for(j=0;j<i;j++)
				{
					Farms_list[i]->client_is_cowfarm(Farms_list[j]);
					Farms_list[j]->client_is_cowfarm(Farms_list[i]);
					Farms_list[i]->client_is_sheepfarm(Farms_list[j]);
					Farms_list[j]->client_is_sheepfarm(Farms_list[i]);
					Farms_list[i]->client_is_chickenfarm(Farms_list[j]);
					Farms_list[j]->client_is_chickenfarm(Farms_list[i]);

				}
			}
		}


		cout<<"----Begin Market----"<<"\n";
		for(i=0;i<Farms_list.size();i++)
		{
			for(j=0;j<Farms_list[i]->list_of_client.size();j++)
			{
//				Farms_list[i]->print_farm();
//				Farms_list[i]->list_of_client[j]->print_farm();
				//Farms_list[i]->buy_products(Farms_list[i]->list_of_client[j]);
				Farms_list[i]->list_of_client[j]->buy_products(Farms_list[i]);
			}
		}


	}






	cout<<"----Buy Animals----"<<"\n";
	for(i=0;i<Farms_list.size();i++)
	{

		Farms_list[i]->cow_farm_market();
		Farms_list[i]->sheep_farm_market();
		Farms_list[i]->chicken_farm_market();

	}
	for(i=0;i<Farms_list.size();i++)
	{
		Farms_list[i]->cow_farm_handel();
		Farms_list[i]->sheep_farm_handel();// instead use buy_annimals function i did this
		Farms_list[i]->chicken_farm_handel();
		Farms_list[i]->Money+=10;
	}

	//if(this->years_of_market!=0)
	{
		for(i=0;i<Farms_list.size();i++)
		{

			//Farms_list[i]->output_farm();
			Farms_list[i]->get_old();// add 1 year to each animal in each farm




		}


	}



}

void Market::fastForwardYears()
{
	int number_years,i,j;


	cout<<"How many years to fast forward?"<<"\n";
	cin >>number_years;

	this->years_of_market=this->years_of_market+number_years;
	while(number_years!=0)
	{
		for(i=0;i<Farms_list.size();i++)
					Farms_list[i]->output_farm();
		cout<<"----Begin Market----"<<"\n";
		for(i=0;i<Farms_list.size();i++)
		{
			for(j=0;j<Farms_list[i]->list_of_client.size();j++)
			{
				Farms_list[i]->list_of_client[j]->buy_products(Farms_list[i]);
			}
		}
		cout<<"----Buy Animals----"<<"\n";
			for(i=0;i<Farms_list.size();i++)
			{

				Farms_list[i]->cow_farm_market();
				Farms_list[i]->sheep_farm_market();
				Farms_list[i]->chicken_farm_market();

			}
			for(i=0;i<Farms_list.size();i++)
			{
				Farms_list[i]->cow_farm_handel();
				Farms_list[i]->sheep_farm_handel();// instead use buy_annimals function i did this
				Farms_list[i]->chicken_farm_handel();
				Farms_list[i]->Money+=10;
			}

			{
				for(i=0;i<Farms_list.size();i++)
				{

					Farms_list[i]->get_old();// add 1 year to each animal in each farm

				}
			}
		number_years--;
	}


}

void Market::printMarketFarms()
{
	cout<<"----Market Farms----"<<"\n";
	int i ;
	for(i=0;i<Farms_list.size();i++)
		Farms_list[i]->print_farm();

}
int Market::getYear()
{
	return this->years_of_market;
}

Market::~Market()
{


	int i;
	for ( it = Farms_list.begin(); it != Farms_list.end(); )
	{
		delete * it;
		 it = Farms_list.erase(it);
	}

	Farms_list.clear();
	Farms_list.shrink_to_fit();

}
