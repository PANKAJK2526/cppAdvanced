cmake_minimum_required(VERSION 3.14)
project(CalculatorUser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/calculator")

find_package(calc REQUIRED)

add_executable(main_exec main.cpp)
target_link_libraries(main_exec PRIVATE calc::calculator)


