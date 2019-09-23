include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests
        basic_check.cpp
        NewTransactionSum_Test.cpp
        SumByAccountReport_Test.cpp
        )

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests mars ${Boost_LIBRARIES})