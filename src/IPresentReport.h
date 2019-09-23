//
// Created by Michal on 05.09.2018.
//

#ifndef MARS_IPRESENTREPORT_H
#define MARS_IPRESENTREPORT_H

#include "MoneyTransfer.h"
class IPresentReport
{
public:
    template<typename T>
    void print(const std::vector<T>&);
};
#endif //MARS_IPRESENTREPORT_H
