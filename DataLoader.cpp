//
// Created by Michal on 28.08.2018.
//

#include "DataLoader.h"


std::stringstream DataLoader::getContent(const std::string &fileName)
{
    file_ = std::ifstream(fileName, std::ifstream::binary);

    auto *buffer = new char[128];
    std::stringstream toReturn;
    delete [] buffer;
    toReturn << buffer;
    return toReturn;
}