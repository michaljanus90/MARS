#include <iostream>
#include <boost/filesystem.hpp>


#include "DataLoader.h"
#include <thread>
#include <chrono>
int main()
{
    auto path = boost::filesystem::current_path();
    path = path.parent_path().string() + "\\log.csv";
    boost::filesystem::path logs(path);

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