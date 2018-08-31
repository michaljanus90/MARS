//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_SUMBYACCOUNTREPORT_H
#define MARS_SUMBYACCOUNTREPORT_H

#include "IRaport.h"

class SumByAccountReport : public IRaport
{
public:
    void genrateReport()  const override;
};


#endif //MARS_SUMBYACCOUNTREPORT_H
