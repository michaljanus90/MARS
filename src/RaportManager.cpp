//
// Created by Michal on 31.08.2018.
//

#include "RaportManager.h"
#include <thread>

void RaportManager::exec(const std::vector<MoneyTransfer> &currentTransfers)
{
    if (currentTransfers.empty())
    {
        std::cout << "No need to run reports\n";
        return;
    }

    transfers.insert(transfers.end(), currentTransfers.begin(), currentTransfers.end());

    std::vector<std::thread> workers;
    for(const auto& report : reports_)
    {
        workers.emplace_back(std::thread([this, &report, &currentTransfers](){
            report.second->genrateReport(transfers, currentTransfers);
        }));
    }

    for(auto && worker : workers)
    {
        worker.join();
    }
}

void RaportManager::presentReports() const
{
    for (const auto& report : reports_)
    {
        auto it = callable_.find(report.first);
        if (it != callable_.end())
            it->second(report.first);
    }
}
