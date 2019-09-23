#include <iostream>
#include <boost/filesystem.hpp>


#include "src/DataLoader.h"
#include <thread>
#include <chrono>

#include "src/NewTransactionSum.h"
#include "src/SumByAccountReport.h"
#include "src/RaportManager.h"
#include <memory>
int main()
{
    RaportManager reportManager;
    reportManager.registerReport(std::make_unique<NewTransactionSum>());
    reportManager.registerReport(std::make_unique<SumByAccountReport>());


    auto path = boost::filesystem::current_path();
    path = path.parent_path().string() + "/log.csv";

    DataLoader dataLoader;
    while (true)
    {
        const auto transactions = dataLoader.getCurrentTransactions(path);

        reportManager.exec(transactions);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
//    return EXIT_SUCCESS;
}
