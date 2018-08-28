//
// Created by Michal on 28.08.2018.
//

#include "MoneyTransfer.h"


bool MoneyTransfer::validateData()
{
    return true;
}

MoneyTransfer::MoneyTransfer(const std::vector<std::string> &parsedRow)
{
    dateTransaction_ = boost::gregorian::from_simple_string(parsedRow[0]);
    time_ = parsedRow[1];
    fromAccount_ = parsedRow[2];
    toAccount_ = parsedRow[3];
    amount_ = std::stod(parsedRow[4]);
}

std::ostream & operator<< (std::ostream &output, const MoneyTransfer &moneyTransfer)
{
    return output << moneyTransfer.dateTransaction_ << " " << moneyTransfer.time_ << " "
                  << moneyTransfer.fromAccount_ << " " << moneyTransfer.toAccount_ << " " << moneyTransfer.amount_
                  << std::endl;
}
