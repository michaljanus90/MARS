//
// Created by Michal on 28.08.2018.
//

#ifndef MARS_DATALOADER_H
#define MARS_DATALOADER_H

#include <boost/filesystem.hpp>
#include <fstream>
#include <sstream>

#include "MoneyTransfer.h"
class DataLoader
{
private:
    long from_ = 0;
    long to_ = 0;
    bool isFileChanged()
    {
        return false;
    }

public:
    DataLoader() = default;
    explicit DataLoader (const std::string &filename);

    std::vector<MoneyTransfer> getCurrentTransactions(const std::string& fileName);
};


#endif //MARS_DATALOADER_H
