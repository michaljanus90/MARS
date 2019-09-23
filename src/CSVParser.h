//
// Created by Michal on 28.08.2018.
//

#ifndef MARS_CSVPARSER_H
#define MARS_CSVPARSER_H

#include <string>
#include "MoneyTransfer.h"

class CSVParser
{
    std::string fileName_;
    void open();

    std::string getLine();

public:
    explicit CSVParser(const std::string& filename);

    MoneyTransfer parse(const std::string &row);

    std::string parse(const std::stringstream &stream);


};


#endif //MARS_CSVPARSER_H
