/*
 * bankClient.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: luis
 */


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

int bankClient::returnBalanceChecking()
{
	return this->balance_Checking;
}

int bankClient::returnBalanceSavings()
{
	return this->balance_Savings;
}

bool bankClient::makeDepositChecking(int M)
{
	bool retVal = true;
	this->balance_Checking += M;

	//IF SOMETHING HAPPENS, IMPLEMENT THE FALSE CASE

	return retVal;
}

bool bankClient::makeDepositSavings(int M)
{
	bool retVal = true;
	this->balance_Savings += M;

	//IF SOMETHING HAPPENS, IMPLEMENT THE FALSE CASE

	return retVal;
}
bankClient::~bankClient()
{
}
