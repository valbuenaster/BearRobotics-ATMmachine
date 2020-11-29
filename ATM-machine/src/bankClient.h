/*
 * bankClient.h
 *
 *  Created on: Nov 28, 2020
 *      Author: luis
 */

#ifndef SRC_BANKCLIENT_H_
#define SRC_BANKCLIENT_H_

class bankClient
{
	int pin_number;
	long long int balance_Savings;
	long long int balance_Checking;

public:
	bankClient(int pin,long long int moneySavings, long long int moneyChecking);

	constexpr bool verifyPIN(int pin);

	~bankClient();
};





#endif /* SRC_BANKCLIENT_H_ */
