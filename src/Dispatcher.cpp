#include "Dispatcher.h"
#include <chrono>
#include <thread>

Dispatcher::Dispatcher(std::unique_ptr<RaportManager> raportManager, const boost::filesystem::path &path):
      raportManager_(std::move(raportManager))
    , data_()
    , path_(path)
{
}

void Dispatcher::run()
{
    std::thread producerThread(&Dispatcher::produceData, this);
    std::thread consumerThread(&Dispatcher::consumeData, this);

    producerThread.join();
    consumerThread.join();
}

void Dispatcher::produceData()
{
    DataLoader dataLoader;
    while(true)
    {
        std::unique_lock<std::mutex> lk(mutex_);
        if(dataLoader.isFileChanged(path_))
        {
            auto transactions = dataLoader.getCurrentTransactions(path_);
            data_.insert(data_.end(), transactions.begin(), transactions.end());
            consumerCond_.notify_one();
        }
        else
        {
            std::cout << "Waiting for data" << std::endl;
            producerCond_.wait(lk, [this]{return data_.empty();; });
        }
        lk.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void Dispatcher::consumeData()
{
    while(true)
    {
        std::unique_lock<std::mutex> lk(mutex_);
        if(!data_.empty())
        {
            auto transactions = data_;
            data_.clear();
            raportManager_->exec(transactions);
            raportManager_->presentReports();
            producerCond_.notify_one();
        }
        else
        {
            std::cout << "waiting for data" << std::endl;
            consumerCond_.wait(lk, [this]{return !data_.empty(); });
        }
        lk.unlock();
    }
}
