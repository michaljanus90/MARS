#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "RaportManager.h"
#include "DataLoader.h"
#include <boost/filesystem.hpp>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <memory>

class Dispatcher
{
public:
    Dispatcher(std::unique_ptr<RaportManager> raportManager, const boost::filesystem::path &path);
    void run();
private:
    void produceData();
    void consumeData();

    std::unique_ptr<RaportManager> raportManager_;
    std::vector<MoneyTransfer> data_;

    std::mutex mutex_;
    std::condition_variable producerCond_;
    std::condition_variable consumerCond_;
    boost::filesystem::path path_;
};

#endif // DISPATCHER_H
