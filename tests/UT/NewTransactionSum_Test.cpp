//
// Created by Michal on 03.09.2018.
//

#include "gtest/gtest.h"
#include <memory>
#include <vector>

#include "NewTransactionSum.h"
#include "MoneyTransfer.h"
#include "PresentResultToCmd.h"
#include "IPresentReport.h"

class NewTransactionSumFixture : public ::testing::Test
{
public:
    NewTransactionSumFixture()
    : newTransactionSum_(std::make_unique<NewTransactionSum>())
    {}

    std::unique_ptr<NewTransactionSum> newTransactionSum_;

};

TEST_F(NewTransactionSumFixture, FirstTest)
{
    MoneyTransfer moneyTransfer({"2014.01.02","12:00:14","67 1234 5678 0000 0000 1234 5678","68 1234 5678 0000 0000 1234 5678","123.45"});
    std::vector<MoneyTransfer> vec{moneyTransfer,moneyTransfer,moneyTransfer,moneyTransfer};
    PresentResultToCmd writer_;

    writer_.getData(newTransactionSum_.get());
    newTransactionSum_->genrateReport(vec,vec);
//    newTransactionSum_->printResult(writer_);
    ASSERT_DOUBLE_EQ(493.8, 123.45*vec.size());
}