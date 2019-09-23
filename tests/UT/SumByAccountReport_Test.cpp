//
// Created by Michal on 03.09.2018.
//

#include "gtest/gtest.h"
#include "SumByAccountReport.h"
#include "MoneyTransfer.h"
#include "PresentResultToCmd.h"
class SumByAccountReportFixure : public ::testing::Test
{
public:
    SumByAccountReportFixure()
    : sumByAccountReport_(std::make_unique<SumByAccountReport>())
    {}
//private:
    std::unique_ptr<SumByAccountReport> sumByAccountReport_;
};

TEST_F(SumByAccountReportFixure, SumByAccountReport_Test1)
{
    MoneyTransfer moneyTransfer({"2014.01.02","12:00:14","67 1234 5678 0000 0000 1234 5678","68 1234 5678 0000 0000 1234 5678","123.45"});
    auto moneyTransfer2 = moneyTransfer;
    moneyTransfer2.fromAccount_ = "88 1234 5678 0000 0000 1234 5678";
//    moneyTransfer2.amount_ = 2222222.22;
    std::vector<MoneyTransfer> vec{moneyTransfer,moneyTransfer2,moneyTransfer,moneyTransfer};

    sumByAccountReport_->genrateReport(vec,{});
    PresentResultToCmd writer_;
    sumByAccountReport_->printResult(writer_);
    EXPECT_EQ(1,2);
}
