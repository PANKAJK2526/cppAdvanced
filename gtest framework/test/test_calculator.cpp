#include<gtest/gtest.h>
#include "../src/calculator.h"

TEST(CalculatorTest, Addition) {
    Calculator calc;
    EXPECT_EQ(calc.add(2,3),5);
}