//
// Created by Michal on 28.08.2018.
//

#ifndef MARS_DATALOADER_H
#define MARS_DATALOADER_H

#include <boost/filesystem.hpp>
#include <fstream>
#include <sstream>
#include <ctime>
#include "MoneyTransfer.h"
#include <chrono>
#include <thread>

class DataLoader
{
private:
    long from_ = 0;
    long to_ = 0;
    std::time_t lastTime_;
    std::chrono::seconds sec_;

public:
    DataLoader() = default;
    explicit DataLoader (const std::string &filename);
    bool isFileChanged(const boost::filesystem::path &path);

    std::vector<MoneyTransfer> getCurrentTransactions(const boost::filesystem::path &path);
};


#endif //MARS_DATALOADER_H
