//
// Created by Michal on 05.09.2018.
//

#ifndef MARS_PRESENTRESULTTOCMD_H
#define MARS_PRESENTRESULTTOCMD_H

#include "IPresentReport.h"
#include <iostream>
class PresentResultToCmd
{
public:
    template <typename T>
    void getData(T *t)
    {
        print(t->getReport());
    }

    template <typename T>
    void print(const std::vector<T>& data, const std::string& prefix)
    {
        for(const auto& x : data)
        {
            std::cout << "XXXXXXXXXXXXXXX   " <<  prefix << ": " << x << std::endl;
        }
    }

    template< typename MapType >
    void print(const MapType & m, const std::string& prefix)
    {
        for (const auto& iter : m)
        {
            std::cout << "%%%%%%%%%%%%   " << prefix << ": " << iter.second << " : " << iter.first << std::endl;
        }
    }
};


#endif //MARS_PRESENTRESULTTOCMD_H
