cmake_minimum_required(VERSION 3.27)
project(AdventOfCode_2023)


set(CMAKE_CXX_STANDARD 23)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(fmt)

#3rd party includes
#include_directories(include)

add_library(tools src/tools.cpp)

add_executable(tpl src/tpl.cpp)
target_link_libraries(tpl PRIVATE fmt::fmt tools)

find_package(Catch2 3 REQUIRED)
add_executable(tests src/test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain tools)

# add all advent of code binaries
add_executable(aoc01_1 src/aoc01_1.cpp )
target_link_libraries(aoc01_1 PRIVATE fmt::fmt tools)

add_executable(aoc01_2 src/aoc01_2.cpp )
target_link_libraries(aoc01_2 PRIVATE fmt::fmt tools)