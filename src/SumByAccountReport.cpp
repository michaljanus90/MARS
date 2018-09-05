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
#include <functional>
namespace
{
    template< class MapType >
    void print_map_reverse(const MapType & m)
    {
        typedef typename MapType::const_reverse_iterator const_reverse_iterator;
        int i=0;
        for( const_reverse_iterator iter = m.rbegin(), iend = m.rend(); iter != iend; ++iter )
        {
            std::cout << i << iter->second << " : " << iter->first << std::endl;
            i++;
        }
    }

    template< class MapType >
    void print_map(const MapType & m)
    {
        typedef typename MapType::const_iterator const_iterator;
        int i=0;
        for( const_iterator iter = m.begin(), iend = m.end(); iter != iend; ++iter )
        {
            std::cout << i << iter->second << " : " << iter->first << std::endl;
            i++;
        }
    }
}
void SumByAccountReport::genrateReport(const std::vector<MoneyTransfer> &allTransfers, const std::vector<MoneyTransfer> &currentTransfers)
{
    typedef boost::bimap<boost::bimaps::set_of<std::string> , boost::bimaps::multiset_of<double,std::greater<double>>> bm_type;
    bm_type transactionsByAccount;

    for (const auto& transfer : allTransfers)
    {
        auto it = transactionsByAccount.left.find(transfer.fromAccount_);
        if (it != transactionsByAccount.left.end())
        {
            transactionsByAccount.left.replace_data( it, (it->second + transfer.amount_) );
        }
        else
        {
            transactionsByAccount.insert(bm_type::value_type(transfer.fromAccount_, transfer.amount_));
        }
    }

    print_map(transactionsByAccount.right);
}