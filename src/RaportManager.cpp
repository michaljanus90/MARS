//
// Created by Michal on 31.08.2018.
//

#include "RaportManager.h"
#include <thread>
#include <vector>

void RaportManager::exec(const std::vector<MoneyTransfer> &currentTransfers)
{
    if (currentTransfers.empty())
    {
        std::cout << "No need to run reports\n";
        return;
    }

    transfers.insert(transfers.end(), currentTransfers.begin(), currentTransfers.end());

    std::vector<std::thread> workers;
    for(const auto& report : reports)
    {
        workers.emplace_back(std::thread([this, &report, &currentTransfers](){
            report->genrateReport(transfers, currentTransfers);
        }));
    }

    for(auto && worker : workers)
    {
        worker.join();
    }
}

void RaportManager::registerReport(std::unique_ptr<IRaport> report)
{
    reports.push_back(std::move(report));
}
