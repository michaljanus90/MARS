#include <iostream>
#include <boost/filesystem.hpp>


#include "src/DataLoader.h"

#include "src/NewTransactionSum.h"
#include "src/SumByAccountReport.h"
#include "src/RaportManager.h"
#include "src/Dispatcher.h"
#include <memory>

int main()
{
    auto reportManager =  std::make_unique<RaportManager>();
    reportManager->registerReport<SumByAccountReport>();
    reportManager->registerReport<NewTransactionSum>();

    reportManager->create<SumByAccountReport>();
    reportManager->create<NewTransactionSum>();

    auto path = boost::filesystem::current_path();
    path = path.parent_path().string() + "/log.csv";

    std::cout<< "Running dispatcher\n";
    Dispatcher dispatcher(std::move(reportManager), path);
    dispatcher.run();

    return 0;
}
