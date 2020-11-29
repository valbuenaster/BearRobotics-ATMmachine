/*
 * bank.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: luis
 */
#include "bank.h"
#include "bankClient.h"

bank::bank()
{
	/*fictitious accounts*/
	bankClient *client1 = new bankClient(1234,6500,300);
	bankClient *client2 = new bankClient(9345,79000,2500);
	bankClient *client3 = new bankClient(2168,3200000,20000);
	bankClient *client4 = new bankClient(3674,200,5);
	bankClient *client5 = new bankClient(2265,6500,0);
	/*fictitious accounts*/

	this->dataBase[1234] = client1;
	this->dataBase[9345] = client2;
	this->dataBase[2168] = client3;
	this->dataBase[3674] = client4;
	this->dataBase[2265] = client5;

	this->clientRequested = nullptr;
}

bool bank::clientPresent(int input_PIN)
{
	bool retVal = false;
	try
	{
		this->clientRequested = this->dataBase.at(input_PIN);
		retVal = true;
	}catch (const std::out_of_range& oor)
	{
	    retVal = false;
	}
	return retVal;
}

long long int bank::RequestBalanceClient(int accType)
{
	long long int retVal = 0;
	switch(accType)
	{
	case 1:
		retVal = this->clientRequested->returnBalanceChecking();
		break;
	case 2:
		retVal = this->clientRequested->returnBalanceSavings();
		break;
	default:
		break;
	}
	return retVal;
}

bool bank::RequestDeposit(int accType,long long int Mon)
{
	bool retVal = false;
	switch(accType)
	{
	case 1:
		retVal = this->clientRequested->makeDepositChecking(Mon);
		break;
	case 2:
		retVal = this->clientRequested->makeDepositSavings(Mon);
		break;
	default:
		break;
	}

	return retVal;
}

bool bank::RequestWithdrawal(int accType,long long int Mon)
{
	bool retVal = false;
	switch(accType)
	{
	case 1:
		retVal = this->clientRequested->makeWithdrawalChecking(Mon);
		break;
	case 2:
		retVal = this->clientRequested->makeWithdrawalSavings(Mon);
		break;
	default:
		break;
	}

	return retVal;
}

bank::~bank()
{
}



