cmake_minimum_required(VERSION 3.0)
project(MARS)

set(CMAKE_CXX_STANDARD 14)
set(Boost_INCLUDE_DIR c:/boost_1_65_1)
set(Boost_LIBRARY_DIR c:/boost_1_65_1/stage/lib)
set(SOURCE_FILES main.cpp)

find_package(Boost)


find_package( Boost 1.65.1 COMPONENTS date_time filesystem)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    include_directories(src)
    add_subdirectory(src)
    add_subdirectory(tests)

    add_executable(MARS ${SOURCE_FILES})
    target_link_libraries(MARS
            mars
            ${Boost_LIBRARIES})
endif()






