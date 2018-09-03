//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_NEWTRANSACTIONSUM_H
#define MARS_NEWTRANSACTIONSUM_H

#include "IRaport.h"
class MoneyTransfer;

class NewTransactionSum : public IRaport
{
public:
    void genrateReport(const std::vector<MoneyTransfer> &allTransfers, const std::vector<MoneyTransfer> &currentTransfers) const override;
};


#endif //MARS_NEWTRANSACTIONSUM_H
