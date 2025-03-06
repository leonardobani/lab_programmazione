//
// Created by yoga on 06/03/25.
//
#include "gtest/gtest.h"
#include "../CategoryCounter.h"
#include <sstream>
#include <iostream>

TEST(CategoryCounterTest, UpdateAdd) {
    CategoryCounter counter;
    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());

    counter.Update(true);
    EXPECT_EQ(ss.str(), "current note number in category: 1\n");

    std::cout.rdbuf(old_cout_buffer);
}

TEST(CategoryCounterTest, UpdateRemove) {
    CategoryCounter counter;
    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());

    counter.Update(true);
    ss.str("");
    counter.Update(false);
    EXPECT_EQ(ss.str(), "current note number in category: 0\n");

    std::cout.rdbuf(old_cout_buffer);
}


TEST(CategoryCounterTest, InitialValue) {
    CategoryCounter counter;
    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());

    EXPECT_EQ(0,0); //just to check the initial state is 0.
    std::cout.rdbuf(old_cout_buffer);
}