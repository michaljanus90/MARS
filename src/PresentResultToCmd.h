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
    void print(const std::vector<T>& data)
    {
        for(const auto& x : data)
        {
            std::cout << "XXXXXXXXXXXXXXX   " << x << std::endl;
        }
    }

    template< typename MapType >
    void print(const MapType & m)
    {
//        typedef typename MapType::const_iterator const_iterator;
//        for( const_iterator iter = m.begin(), iend = m.end(); iter != iend; ++iter )
        for (const auto& iter : m)
        {
            std::cout << "%%%%%%%%%%%%   " << iter.second << " : " << iter.first << std::endl;
        }
    }

//    template <typename T>
//    void print(const T t)
//    {
//        std::cout << t << std::endl;
//    }

};


#endif //MARS_PRESENTRESULTTOCMD_H
