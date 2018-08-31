//
// Created by Michal on 28.08.2018.
//

#include "DataLoader.h"

#include "CSVParser.h"
#include <iostream>
std::vector<MoneyTransfer> DataLoader::getCurrentTransactions(const std::string &fileName)
{
    CSVParser parser(fileName);
//    file_ = std::ifstream(fileName, std::ifstream::binary);

    std::ifstream file_(fileName);
    std::vector<MoneyTransfer> transfers;
    if (file_)
    {
        file_.seekg(0, file_.end);
        to_ = file_.tellg();
        file_.seekg(from_, file_.beg);



        while (to_ != file_.tellg())
        {
            std::string row;
            getline(file_, row);
            transfers.push_back(parser.parse(row));
        }
        from_ = to_;
        file_.clear();
        file_.close();
    }
    return transfers;
}