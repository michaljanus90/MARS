//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_IGENERATOR_H
#define MARS_IGENERATOR_H

#include <vector>

class MoneyTransfer;
class IRaport
{
public:
    virtual void genrateReport(const std::vector<MoneyTransfer> &allTransfers, const std::vector<MoneyTransfer> &currentTransfers) = 0;
    virtual ~IRaport(){}
};

#endif //MARS_IGENERATOR_H
