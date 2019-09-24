//
// Created by Michal on 28.08.2018.
//

#include "DataLoader.h"

#include "CSVParser.h"
#include <iostream>

bool DataLoader::isFileChanged(const boost::filesystem::path &path)
{
    auto lastWriteTime = boost::filesystem::last_write_time(path);
    if (lastWriteTime != lastTime_)
    {
        lastTime_ = lastWriteTime;
        return true;
    }
    return false;
}


std::vector<MoneyTransfer> DataLoader::getCurrentTransactions(const boost::filesystem::path &path)
{
    CSVParser parser(path.string());
    std::vector<MoneyTransfer> transfers = {};

//    if (isFileChanged(path))
    {
        std::ifstream file_(path.string());

        if (file_)
        {
            file_.seekg(0, file_.end);
            to_ = file_.tellg();
            file_.seekg(from_, file_.beg);


            while (to_ != file_.tellg()) {
                std::string row;
                getline(file_, row);
                transfers.push_back(parser.parse(row));
            }
            from_ = to_;
            file_.clear();
            file_.close();
        }
    }
    return transfers;
}
