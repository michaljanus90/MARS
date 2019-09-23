//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_NEWTRANSACTIONSUM_H
#define MARS_NEWTRANSACTIONSUM_H

#include "IRaport.h"

class MoneyTransfer;

class NewTransactionSum : public IRaport
{
    double sumOfNewTransactions_;
public:
    void genrateReport(const std::vector<MoneyTransfer> &allTransfers, const std::vector<MoneyTransfer> &currentTransfers) override;
    double getSumOfNewTransactions() const;

    std::vector<double> getReport()
    {
        return {sumOfNewTransactions_};
    }

    template <typename Writer>
    void printResult(Writer writer)
    {
        std::vector<double> vec{sumOfNewTransactions_};
        writer.print(vec);
    };
};


#endif //MARS_NEWTRANSACTIONSUM_H
