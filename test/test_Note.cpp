//
// Created by yoga on 06/03/25.
//
#include "gtest/gtest.h"
#include "../Note.h"
#include <sstream>
#include <iostream>

TEST(NoteTest, ConstructorAndPrint) {
    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());

    Note note("TestTitle", "TestBody", false, false);
    std::string expectedOutput = "New note created successfully\n\033[1mTestTitle\033[0m\nTestBody\n\n";
    EXPECT_EQ(ss.str(), expectedOutput);

    std::cout.rdbuf(old_cout_buffer);
}

TEST(NoteTest, EditTitle) {
    Note note("TestTitle", "TestBody", false, false);

    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());
    ss.str("");

    note.editTitle("NewTitle");
    std::string expectedOutput = "\033[1mNewTitle\033[0m\nTestBody\n\n";
    EXPECT_EQ(ss.str(), expectedOutput);

    std::cout.rdbuf(old_cout_buffer);
}

TEST(NoteTest, EditBody) {
    Note note("TestTitle", "TestBody", false, false);

    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());
    ss.str("");

    note.editBody("NewBody");
    std::string expectedOutput = "\033[1mTestTitle\033[0m\nNewBody\n\n";
    EXPECT_EQ(ss.str(), expectedOutput);

    std::cout.rdbuf(old_cout_buffer);
}

TEST(NoteTest, BlockedEdit) {
    Note note("TestTitle", "TestBody", true, false);

    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());
    ss.str("");

    note.editTitle("NewTitle");
    EXPECT_TRUE(ss.str().find("please unlock before edit") != std::string::npos);
    ss.str("");

    note.editBody("NewBody");
    EXPECT_TRUE(ss.str().find("please unlock before edit") != std::string::npos);

    std::cout.rdbuf(old_cout_buffer);
}

TEST(NoteTest, BlockAndUnblock) {
    Note note("TestTitle", "TestBody", false, false);
    note.blockNote(true);
    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());
    ss.str("");

    note.printNote();
    EXPECT_TRUE(ss.str().find("🔒") != std::string::npos);
    std::cout.rdbuf(old_cout_buffer);
    note.blockNote(false);
    ss.str("");
    old_cout_buffer = std::cout.rdbuf(ss.rdbuf());
    note.printNote();
    EXPECT_FALSE(ss.str().find("🔒") != std::string::npos);
    std::cout.rdbuf(old_cout_buffer);
}

TEST(NoteTest, SpecialNote) {
    Note note("TestTitle", "TestBody", false, false);
    note.editSpecial(true);
    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());
    ss.str("");

    note.printNote();
    EXPECT_TRUE(ss.str().find("⭐") != std::string::npos);
    std::cout.rdbuf(old_cout_buffer);
    note.editSpecial(false);
    ss.str("");
    old_cout_buffer = std::cout.rdbuf(ss.rdbuf());
    note.printNote();
    EXPECT_FALSE(ss.str().find("⭐") != std::string::npos);
    std::cout.rdbuf(old_cout_buffer);
}