//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_NEWTRANSACTIONSUM_H
#define MARS_NEWTRANSACTIONSUM_H

#include "IRaport.h"

class NewTransactionSum : public IRaport
{
public:
    void genrateReport()  const override;
};


#endif //MARS_NEWTRANSACTIONSUM_H
