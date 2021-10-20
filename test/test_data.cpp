/** Copyright 2021 Sakshi Kakde, Siddharth Telang, Anubhav Paras */

#include <gtest/gtest.h>

#include <data.hpp>

TEST(data_test, test_getter_setter) {
    Data<int> integerData;
    int x = 10;
    integerData.setData(x);
    EXPECT_EQ(x, integerData.getData());
}

TEST(data_test, test_param_constructor) {
    int x = 10;
    Data<int> integerData(x);
    EXPECT_EQ(x, integerData.getData());
}

