//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_RAPORTMANAGER_H
#define MARS_RAPORTMANAGER_H

#include <vector>
#include "IRaport.h"
#include <memory>

class RaportManager
{
public:
    void registerReport(std::unique_ptr<IRaport> report);
    void exec();

private:
    std::vector<std::unique_ptr<IRaport>> reports;
};


#endif //MARS_RAPORTMANAGER_H
