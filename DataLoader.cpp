//
// Created by Michal on 28.08.2018.
//

#include "DataLoader.h"

#include "CSVParser.h"
#include <iostream>
std::vector<MoneyTransfer> DataLoader::getCurrentTransactions(const std::string &fileName)
{
    CSVParser parser(fileName);
    file_ = std::ifstream(fileName, std::ifstream::binary);

    file_.seekg(0, this->file_.end);
    to_ = file_.tellg();
    std::cout << to_ << std::endl;
    file_.seekg(0, this->file_.beg);


    std::vector<MoneyTransfer> transfers;
    while (!file_.eof())
    {
        std::string row;
        getline(file_, row);
        transfers.push_back(parser.parse(row));
    }
    from_ = to_;
    file_.close();
    return transfers;
}