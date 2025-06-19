cmake_minimum_required(VERSION 3.14)
project(CppTddProject)

enable_testing()

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
FetchContent_MakeAvailable(googletest)

# Project Sources
add_library(calculator src/calculator.cpp)

# Unit Tests
add_executable(unit_tests test/test_calculator.cpp)
target_link_libraries(unit_tests calculator gtest gtest_main)
add_test(NAME AllTests COMMAND unit_tests)
