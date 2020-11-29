/*
 * main.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: luis
 */

#include <iostream>
#include "bank.h"

using namespace std;




int main()
{
	bank *CentralBank = new bank();
	char insertCard = ' ';


	cout<<"ATM CONTROLLER"<<endl;
	while(insertCard!='@')
	{
		cout<<"please insert card (@ for card inserted)"<<endl;
		cin >> insertCard;
	}


	cout<<"Pl";
}




