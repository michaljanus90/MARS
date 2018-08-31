//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_IGENERATOR_H
#define MARS_IGENERATOR_H

class IRaport
{
public:
    virtual void genrateReport() const = 0;
    virtual ~IRaport(){}
};

#endif //MARS_IGENERATOR_H
