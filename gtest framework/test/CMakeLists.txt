add_executable(unit_tests test_calculator.cpp)
target_link_libraries(unit_tests calculator gtest gtest_main)

add_test(NAME AllTests COMMAND unit_tests)
