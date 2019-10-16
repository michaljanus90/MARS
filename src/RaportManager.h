//
// Created by Michal on 31.08.2018.
//

#ifndef MARS_RAPORTMANAGER_H
#define MARS_RAPORTMANAGER_H

#include <vector>
#include <unordered_map>
#include "IRaport.h"
#include <memory>
#include "MoneyTransfer.h"
#include <typeindex>
#include <type_traits>
#include "PresentResultToCmd.h"

class RaportManager
{
    std::vector<MoneyTransfer> transfers;
public:
    void exec(const std::vector<MoneyTransfer> &currentTransfers);

    template<typename T>
    void registerReport()
    {
        static_assert(std::is_base_of<IRaport, T>::value, "Should derived from IRaport");
        if (!isRegistered<T>())
            reports_[std::type_index(typeid(T))] = nullptr;
    }

    template<typename T>
    void create()
    {
        const auto idx = std::type_index(typeid(T));
        auto it = reports_.find(idx);
        if (it != reports_.end() and it->second == nullptr)
        {
            it->second = std::make_shared<T>();
            makeCallable<T>();
        }
    }

    void presentReports() const;

private:
    template<typename T>
    void makeCallable()
    {
        auto func = [this](std::type_index idx) {
          auto it = reports_.find(idx);
          if (it != reports_.end())
          {
              auto ptr = static_cast<T*>(it->second.get());
              ptr->printResult(presenter_);
          }
          else
          {
              std::cout << "Not Found in reports: " << idx.name() << std::endl;
          }
        };
        callable_[std::type_index(typeid(T))] = func;
    }
    template<typename T>
    bool isRegistered() const
    {
        return reports_.find(std::type_index(typeid(T))) != reports_.end();
    }

    PresentResultToCmd presenter_;
    std::unordered_map<std::type_index, std::shared_ptr<IRaport>> reports_;
    std::unordered_map<std::type_index, std::function<void(std::type_index)>> callable_;
};


#endif //MARS_RAPORTMANAGER_H
