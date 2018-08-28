//
// Created by Michal on 28.08.2018.
//

#ifndef MARS_DATALOADER_H
#define MARS_DATALOADER_H

#include <boost/filesystem.hpp>
#include <fstream>
#include <sstream>

class DataLoader
{
private:
    boost::filesystem::path path_;
    std::ifstream file_;
    size_t pos_ = 0;
    size_t lenght_ = 0;
public:
    DataLoader() = default;
    explicit DataLoader (const std::string &filename);

    std::stringstream getContent(const std::string& fileName);
    virtual ~DataLoader()
    {
        if (file_.is_open())
            file_.close();
    }
};


#endif //MARS_DATALOADER_H
