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
	int input_PIN = 0;
	char accountType = ' ';
	int activity = -1;

	cout<<"ATM CONTROLLER"<<endl;
	while(insertCard!='@')
	{
		cout<<"\nplease insert card (@ for card inserted)"<<endl;
		cin >> insertCard;
	}

	cout<<"\nNow, please write your 4 digits PIN number."<<endl;
	cin >> input_PIN;

	/*WHEN THE CARD IS INSERTED ON A REAL ATM MACHINE, THE NUMBER OF THE ACCOUNT IS READ AND WITH THE
	ACCOUNT NUMBER, THE INFO OF THE CLIENT IS FOUND. THE INFO IS SUPPORTED BY A VALID PIN NUMBER.
	FOR THIS IMPLEMENTATION, HOWEVER, THE SEARCH ON THE IMPROVISED DATA BASED IS DONE WITH THE PIN NUMBER
	ONLY.

	THE CORRECT WAY IS TO MAKE THE IMPROVISED DATA BASED INDEX WITH THE ACCOUNT NUMBER, WHICH IS UNIQUE.
	TWO PEOPLE COULD HAVE THE SAME PIN NUMBER BUT NOT THE SAME ACCOUNT NUMBER
	*/
	int counter = 1;
	while(!CentralBank->clientPresent(input_PIN))
	{
		cout << "\nSorry, we could not verify you PIN. Please try again..."<<endl;
		cin >>input_PIN;

		if(counter > 2)
		{
			cout << "\nMaximum number of PIN attempts."<<endl;
			return -1;
		}

		counter++;
	}

	cout<<endl;
	while(accountType!='c'||accountType!='C'||accountType!='s'||accountType!='S')
	{
		cout <<"\nPlease select an account. (C)hecking or (S)avings"
		cin >> accountType;
	}

	counter = 1;
	while(activity!=1 ||activity!=2 ||activity!=3 )
	{
		cout << "What would you like to do?"<<endl;
		cout << "\t(1) Check your balance"<<endl;
		cout << "\t(2) Do a deposit"<<endl;
		cout << "\t(3) Do a withdrawal"<<endl;

		cin >> activity;

		if(counter > 2)
		{
			cout << "\nYou need to type a valid option. 1, 2 or 3. Please try later today."<<endl;
			return -1;
		}
	}

	cout<<"Have a nice day";


	return 0;
}




