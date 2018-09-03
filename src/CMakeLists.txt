project(mars)

set(HEADER_FILES
        CSVParser.h
        DataLoader.h
        IRaport.h
        MoneyTransfer.h
        NewTransactionSum.h
        RaportManager.h
        SumByAccountReport.h)

set(SOURCE_FILES
        CSVParser.cpp
        DataLoader.cpp
        MoneyTransfer.cpp
        NewTransactionSum.cpp
        RaportManager.cpp
        SumByAccountReport.cpp)

#target_link_libraries(mars ${Boost_LIBRARIES})

add_library(mars ${SOURCE_FILES} ${HEADER_FILES})