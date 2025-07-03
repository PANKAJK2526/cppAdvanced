#include <gtest/gtest.h>
#include "calculator/calculator.h"

TEST(CalculatorTest, AddPositive) {
    EXPECT_EQ(add(3, 4), 7);
}

TEST(CalculatorTest, AddNegative) {
    EXPECT_EQ(add(-2, -5), -7);
}

TEST(CalculatorTest, AddMixed) {
    EXPECT_EQ(add(-3, 5), 2);
}
