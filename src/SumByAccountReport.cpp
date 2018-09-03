//
// Created by Michal on 31.08.2018.
//

#include "SumByAccountReport.h"
#include "MoneyTransfer.h"
#include <iostream>
#include <map>
#include <algorithm>
#include "boost/bimap.hpp"
#include "boost/bimap/set_of.hpp"
#include <boost/bimap/multiset_of.hpp>
#include "boost/bimap/list_of.hpp"
#include "boost/bimap/vector_of.hpp"

namespace
{
    template< class MapType >
    void print_map(const MapType & m)
    {
        typedef typename MapType::const_reverse_iterator const_reverse_iterator;
        int i=0;
        for( const_reverse_iterator iter = m.rbegin(), iend = m.rend(); iter != iend; ++iter )
        {
            std::cout << i << iter->second << " : " << iter->first << std::endl;
            i++;
        }
    }
}
void SumByAccountReport::genrateReport(const std::vector<MoneyTransfer> &allTransfers, const std::vector<MoneyTransfer> &currentTransfers)
{
    boost::bimap<boost::bimaps::set_of<std::string> , boost::bimaps::vector_of<double>> transactionsByAccount;

    for (const auto& transfer : allTransfers)
    {
        transactionsByAccount.left[transfer.fromAccount_] += transfer.amount_;
    }
    print_map(transactionsByAccount.right);
}