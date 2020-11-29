/*
 * main.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: luis
 */

#include <iostream>
#include <string>
#include "bank.h"

using namespace std;

void takingMoney()
{
	for(int ii=0;ii<5;ii++)cout << "Taking money..."<<endl;
}


int main()
{
	bank *CentralBank = new bank();
	string insertCard = " ";
	string cycle = " ";
	int input_PIN;
	string accountType;
	int accType;
	int activity;
	string temp = " ";
	long long int money;

	cout<<"ATM CONTROLLER"<<endl;
	while(insertCard.find('@')==string::npos)
	{
		cout<<"\nplease insert card (\"@\" for card inserted)"<<endl;
		cin >> insertCard;
	}

	//START ALL OVER HERE
	while(true)
	{
		input_PIN = 0;
		accountType = ' ';
		accType = 0;
		activity = -1;
		money = 0;
		temp = " ";

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
		while(true)
		{
			cout <<"\nPlease select an account. (C)hecking or (S)avings"<<endl;
			cin >> accountType;
			//cout<<"accountType = "<<accountType<<endl;
			if(accountType.find('c')!=string::npos||accountType.find('C')!=string::npos)
			{
				accType = 1;
				break;
			}

			if(accountType.find('s')!=string::npos||accountType.find('S')!=string::npos)
			{
				accType = 2;
				break;
			}
		}

		counter = 1;
		while(true)
		{
			cout << "What would you like to do?"<<endl;
			cout << "\t(1) Check your balance"<<endl;
			cout << "\t(2) Do a deposit"<<endl;
			cout << "\t(3) Do a withdrawal"<<endl;

			cin >> activity;
			if(activity==1 ||activity==2 ||activity==3 )
			{
				break;
			}
			if(counter > 2)
			{
				cout << "\nYou need to type a valid option. 1, 2 or 3. Please try later today."<<endl;
				return -1;
			}
			counter++;
		}

		switch(activity)
		{
		case 1:
				cout<<"Your balance is "<<CentralBank->RequestBalanceClient(accType)<<endl;
				break;
		case 2:
				cout<<"How much money are you going to deposit?"<<endl;
				cin >> money;

				temp = " ";

				while(temp.find("P")==string::npos)
				{
					cout <<"Type \"P\" to emulate a sensor sending the signal that you put the money on the tray"<<endl;
					cin >> temp;
				}

				if(CentralBank->RequestDeposit(accType,money))
				{
					takingMoney();
					cout<<"Your transaction was conducted successfully"<<endl;
				}else{
					cout<<"There was something wrong. Please talk to one of our representatives at (XXX)-XXX XXX"<<endl;
				}
				break;
		case 3:
				cout<<"How much money are you going to withdraw?"<<endl;
				cin >> money;

				if(CentralBank->RequestWithdrawal(accType,money))
				{

					temp = " ";

					while(temp.find("T")==string::npos)
					{
						cout <<"Type \"T\" to emulate a sensor sending the signal that you took the money from the tray"<<endl;
						cin >> temp;
					}

					cout<<"Your transaction was conducted successfully"<<endl;
				}else{
					cout<<"There are not enough funds to conduct the transaction"<<endl;
				}

				break;
		default:
				break;
		}

		cout<<"Press any letter if you want to conduct another operation, press \"~\" to get out"<<endl;
		cin >> cycle;

		//cout<<"cycle = "<<cycle<<endl;
		if(cycle.find('~')!=string::npos)break;
	}

	cout<<"Have a nice day";


	return 0;
}




