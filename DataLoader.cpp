//
// Created by Michal on 28.08.2018.
//

#include "DataLoader.h"


std::stringstream DataLoader::getContent(const std::string &fileName)
{
    file_ = std::ifstream(fileName, std::ifstream::binary);


}