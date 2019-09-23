//
// Created by Michal on 28.08.2018.
//

#include "CSVParser.h"

std::string CSVParser::getLine()
{
    return "2014.04.03T12:00:14, 67 1234 5678 0000 0000 1234 5678, 68 1234 5678 0000 0000 1234 5678, 123.45";
}

void CSVParser::open()
{

}

CSVParser::CSVParser(const std::string &filename)
: fileName_(filename)
{}

MoneyTransfer CSVParser::parse(const std::string &row)
{
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep(",T");

    tokenizer tokens(row, sep);
    std::vector<std::string> parsedRow(tokens.begin(), tokens.end());
    return MoneyTransfer(parsedRow);
}

std::string CSVParser::parse(const std::stringstream &stream)
{
    return "";
}