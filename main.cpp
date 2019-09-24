#include <iostream>
#include <boost/filesystem.hpp>


#include "src/DataLoader.h"

#include "src/NewTransactionSum.h"
#include "src/SumByAccountReport.h"
#include "src/RaportManager.h"
#include "src/Dispatcher.h"
#include <memory>

#include <thread>
int main()
{
    auto reportManager =  std::make_unique<RaportManager>();
    reportManager->registerReport(std::make_unique<NewTransactionSum>());
    reportManager->registerReport(std::make_unique<SumByAccountReport>());


    auto path = boost::filesystem::current_path();
    path = path.parent_path().string() + "/log.csv";

    std::cout<< "Running dispatcher\n";
    Dispatcher dispatcher(std::move(reportManager), path);
    dispatcher.run();

//    while (true)
//    {
//        const auto transactions = dataLoader.getCurrentTransactions(path);

//        reportManager.exec(transactions);
//        std::this_thread::sleep_for(std::chrono::seconds(2));
//    }

//    return EXIT_SUCCESS;
}
