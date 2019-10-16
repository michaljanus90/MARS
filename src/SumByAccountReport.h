//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_SUMBYACCOUNTREPORT_H
#define MARS_SUMBYACCOUNTREPORT_H

#include "IRaport.h"
#include "boost/bimap.hpp"
#include "boost/bimap/set_of.hpp"
#include <boost/bimap/multiset_of.hpp>

class MoneyTransfer;

class SumByAccountReport : public IRaport
{
    typedef boost::bimap<boost::bimaps::set_of<std::string> , boost::bimaps::multiset_of<double,std::greater<double>>> bm_type;
    bm_type transactionsByAccount;
public:
    void genrateReport(const std::vector<MoneyTransfer> &allTransfers, const std::vector<MoneyTransfer> &currentTransfers) override;

    template <typename Writer>
    void printResult(Writer writer)
    {
        writer.print(transactionsByAccount.right, "SumByAccountReport");
    }
};


#endif //MARS_SUMBYACCOUNTREPORT_H
