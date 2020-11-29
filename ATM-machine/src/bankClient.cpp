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
constexpr int bankClient::returnBalanceChecking()
{
	return this->balance_Checking;
}

constexpr int bankClient::returnBalanceSavings()
{
	return this->balance_Savings;
}

bankClient::~bankClient()
{

}
