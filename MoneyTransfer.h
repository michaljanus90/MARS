//
// Created by Michal on 28.08.2018.
//

#ifndef MARS_MONEYTRANSFER_H
#define MARS_MONEYTRANSFER_H

#include <string>
#include <vector>
#include <ostream>
#include <boost/tokenizer.hpp>
#include <boost/date_time.hpp>


class MoneyTransfer
{
private:
    boost::gregorian::date dateTransaction_;
    std::string time_;
    std::string fromAccount_;
    std::string toAccount_;
    double amount_ = 0;

    bool validateData();
public:
    MoneyTransfer() = default;
    explicit MoneyTransfer(const std::vector<std::string> &parsedRow);

    friend std::ostream & operator<< (std::ostream &output, const MoneyTransfer &moneyTransfer);
};




#endif //MARS_MONEYTRANSFER_H
