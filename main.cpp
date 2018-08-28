#include <iostream>

#include <string>
#include <vector>
#include <boost/algorithm/string/replace.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <limits>
#include <sstream>


#include "MoneyTransfer.h"
#include "CSVParser.h"

int main()
{

    auto x = boost::filesystem::current_path();
    x = x.parent_path().string() + "\\log.csv";
//    std::cout << x << std::endl;
    boost::filesystem::path logs(x);

    CSVParser parser(x.string());
    std::vector<MoneyTransfer> transfers;

    std::ifstream file(x.string(), std::ifstream::binary);
    size_t lastPos = 0;
    if (file.is_open()) {
        std::string line;
        file.seekg(0, file.end);
        lastPos = file.tellg();
        file.seekg(0, file.beg);

        char * buffer = new char[lastPos+1];
        file.read(buffer, lastPos);
        buffer[lastPos] = EOF;
        std::cout << "Last POS: " << lastPos  << std::endl;

        std::stringstream temp;
        temp << buffer;
        std::cout << temp.str() << "\nendl\n";

        std::string d;
        while (getline(temp, d, '\n')) {
            transfers.push_back(parser.parse(d));
        }

        delete [] buffer;
        file.close();
    }

    for (const auto& transfer : transfers)
    {
        std::cout << transfer;
    }

//    std::cout << "POS: " << lastPos << std::endl;

    return EXIT_SUCCESS;
}