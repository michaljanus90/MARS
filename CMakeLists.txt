cmake_minimum_required(VERSION 3.0)
project(MARS)

set(CMAKE_CXX_STANDARD 14)

set(Boost_INCLUDE_DIR c:/boost_1_65_1)
set(Boost_LIBRARY_DIR c:/boost_1_65_1/stage/lib)
find_package(Boost)

find_package( Boost 1.65.1 COMPONENTS date_time filesystem)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    add_executable( MARS
                    main.cpp
                    MoneyTransfer.cpp DataLoader.cpp DataLoader.h CSVParser.cpp CSVParser.h IRaport.h RaportManager.cpp RaportManager.h NewTransactionSum.cpp NewTransactionSum.h SumByAccountReport.cpp SumByAccountReport.h)
    target_link_libraries(MARS ${Boost_LIBRARIES})# ${Boost_DATE_TIME_LIBRARY} ${BOOST_FILESYSTEM_LIBRARY})
endif()





