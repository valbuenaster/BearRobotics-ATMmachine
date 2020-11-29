/*
 * bank.h
 *
 *  Created on: Nov 28, 2020
 *      Author: luis
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include <map>
#include "bankClient.h"

class bank
{
	bankClient * clientRequested;
	std::map<int,bankClient*> dataBase;
public:
	bank();

	bool clientPresent(int input_PIN);
	long long int RequestBalanceClient(int accType);
	bool RequestDeposit(int accType, long long int Mon);
	bool RequestWithdrawal(int accType,long long int money);
	~bank();
};





#endif /* SRC_BANK_H_ */
