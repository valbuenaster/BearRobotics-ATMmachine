/*
 * bankClient.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: luis
 */

#include <limits.h>
#include "bankClient.h"


bankClient::bankClient(int pin,long long int moneySavings,long long int moneyChecking)
{
	this->pin_number = pin;
	this->balance_Checking = moneyChecking;
	this->balance_Savings = moneySavings;
}
constexpr bool bankClient::verifyPIN(int pin)
{
	return (pin&&this->pin_number);
}

long long int bankClient::returnBalanceChecking()
{
	return this->balance_Checking;
}

long long int bankClient::returnBalanceSavings()
{
	return this->balance_Savings;
}

bool bankClient::makeDepositChecking(long long int M)
{
	bool retVal = true;

	if(LLONG_MAX - this->balance_Checking < M)//Overflow
	{
		retVal = false;
	}else{
		this->balance_Checking += M;
		retVal = true;
	}

	//IF SOMETHING HAPPENS, IMPLEMENT THE FALSE CASE
	//LIKE A COMMUNICATION FAILURE WITH THE REMOTE DATABASE OF THE BANK
	return retVal;
}

bool bankClient::makeDepositSavings(long long int M)
{
	bool retVal = true;

	if(LLONG_MAX - this->balance_Checking < M)//Overflow
	{
		retVal = false;
	}else{
		this->balance_Savings += M;
		retVal = true;
	}

	//IF SOMETHING HAPPENS, IMPLEMENT THE FALSE CASE
	//LIKE A COMMUNICATION FAILURE WITH THE REMOTE DATABASE OF THE BANK

	return retVal;
}

bool bankClient::makeWithdrawalChecking(long long int M)
{
	bool retVal = true;

	if(this->balance_Checking - M < 0)
	{
		retVal = false;
	}else{
		this->balance_Checking -= M;
		retVal = true;
	}
	//IF SOMETHING HAPPENS, IMPLEMENT THE FALSE CASE
	//LIKE A COMMUNICATION FAILURE WITH THE REMOTE DATABASE OF THE BANK
	return retVal;
}

bool bankClient::makeWithdrawalSavings(long long int M)
{
	bool retVal = true;

	if(this->balance_Savings - M < 0)
	{
		retVal = false;
	}else
	{
		this->balance_Savings -= M;
		retVal = true;
	}

	//IF SOMETHING HAPPENS, IMPLEMENT THE FALSE CASE
	//LIKE A COMMUNICATION FAILURE WITH THE REMOTE DATABASE OF THE BANK

	return retVal;
}


bankClient::~bankClient()
{
}
