#include <iostream>
#include <boost/filesystem.hpp>


#include "DataLoader.h"
#include <thread>
#include <chrono>

#include "NewTransactionSum.h"
#include "SumByAccountReport.h"
#include "RaportManager.h"
#include <memory>
int main()
{

    //
    //
    RaportManager reportManager;
    reportManager.registerReport(std::make_unique<NewTransactionSum>());
    reportManager.registerReport(std::make_unique<SumByAccountReport>());

    reportManager.exec();
    //
    //

    auto path = boost::filesystem::current_path();
    path = path.parent_path().string() + "\\log.csv";

    DataLoader dataLoader;
    while (true)
    {
        auto transactions = dataLoader.getCurrentTransactions(path);

        for (const auto &transaction : transactions)
        {
            std::cout << transaction;
        }
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
//    return EXIT_SUCCESS;
}