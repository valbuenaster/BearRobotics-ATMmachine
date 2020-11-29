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
	std::map<int,bankClient*> dataBase;
public:
	bank();

	~bank();
};





#endif /* SRC_BANK_H_ */
