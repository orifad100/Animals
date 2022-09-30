/*
 * Exception
 *
 *  Created on: Jan 8, 2022
 *      Author: ise
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_
#include <iostream>
#include <exception>
using namespace std;

class Cowexception: public exception
{
	virtual const char* what () const throw(){
		return "Insert valid number of cow farms";
	}
}Cowexception;


class Sheepexception: public exception
{
	virtual const char* what () const throw(){
			return "Insert valid number of sheep farms";
		}

}Sheepexception;

class Chickenexception: public exception
{
	virtual const char* what () const throw(){
			return "Insert valid number of chicken farms";
		}

}Chickenexception;







#endif /* EXCEPTION_H_ */
