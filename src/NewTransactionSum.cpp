//
// Created by Michal on 31.08.2018.
//

#include <iostream>
#include "NewTransactionSum.h"
#include "MoneyTransfer.h"

void NewTransactionSum::genrateReport(const std::vector<MoneyTransfer> &allTransfers, const std::vector<MoneyTransfer> &currentTransfers)
{
    if (!currentTransfers.empty())
    {
        std::cout << "NOT EMPTY\n";
        double sum = 0.;
        for (const auto& trans : currentTransfers)
        {
            std::cout << trans;
            sum += trans.amount_;
        }
        sumOfNewTransactions_ = sum;
        std::cout << "SUM OF NEW TRANSACTIONS: " << sum << std::endl;

    }
}
double NewTransactionSum::getSumOfNewTransactions() const
{
    return sumOfNewTransactions_;
}