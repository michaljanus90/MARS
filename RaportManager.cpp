//
// Created by Michal on 31.08.2018.
//

#include "RaportManager.h"

void RaportManager::exec()
{
    for(const auto& report : reports)
        report->genrateReport();
}

void RaportManager::registerReport(std::unique_ptr<IRaport> report)
{
    reports.push_back(std::move(report));
}