//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_RAPORTMANAGER_H
#define MARS_RAPORTMANAGER_H

#include <vector>
#include "IRaport.h"
#include <memory>
#include "MoneyTransfer.h"

class RaportManager
{
    std::vector<MoneyTransfer> transfers;
public:
    void registerReport(std::unique_ptr<IRaport> report);
    void exec(const std::vector<MoneyTransfer> &currentTransfers);

private:
    std::vector<std::unique_ptr<IRaport>> reports;
};


#endif //MARS_RAPORTMANAGER_H
