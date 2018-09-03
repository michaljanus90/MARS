//
// Created by Michal on 31.08.2018.
//

#include "RaportManager.h"

void RaportManager::exec(const std::vector<MoneyTransfer> &currentTransfers)
{
    transfers.insert(transfers.end(), currentTransfers.begin(), currentTransfers.end());
    for(const auto& report : reports)
        report->genrateReport(transfers, currentTransfers);
}

void RaportManager::registerReport(std::unique_ptr<IRaport> report)
{
    reports.push_back(std::move(report));
}