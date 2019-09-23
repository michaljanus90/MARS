//
// Created by Michal on 31.08.2018.
//

#include "SumByAccountReport.h"
#include "MoneyTransfer.h"
#include <iostream>

void SumByAccountReport::genrateReport(const std::vector<MoneyTransfer> &allTransfers, const std::vector<MoneyTransfer> &currentTransfers)
{
    for (const auto& transfer : allTransfers)
    {
        auto it = transactionsByAccount.left.find(transfer.fromAccount_);
        if (it != transactionsByAccount.left.end())
        {
            transactionsByAccount.left.replace_data( it, (it->second + transfer.amount_) );
        }
        else
        {
            transactionsByAccount.insert(bm_type::value_type(transfer.fromAccount_, transfer.amount_));
        }
    }

//    print_map(transactionsByAccount.right);
}