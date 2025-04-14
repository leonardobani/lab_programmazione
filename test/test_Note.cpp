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
    std::string expectedOutput = "New note created successfully\n";
    EXPECT_EQ(ss.str(), expectedOutput);

    std::cout.rdbuf(old_cout_buffer);
}

TEST(NoteTest, EditTitle) {
    Note note("TestTitle", "TestBody", false, false);

    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());
    ss.str("");

    note.editTitle("NewTitle");
    std::string expectedOutput = "NewTitle\nTestBody\n\n";
    EXPECT_EQ(ss.str(), expectedOutput);

    std::cout.rdbuf(old_cout_buffer);
}

TEST(NoteTest, EditBody) {
    Note note("TestTitle", "TestBody", false, false);

    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());
    ss.str("");

    note.editBody("NewBody");
    std::string expectedOutput = "TestTitle\nNewBody\n\n";
    EXPECT_EQ(ss.str(), expectedOutput);

    std::cout.rdbuf(old_cout_buffer);
}

TEST(NoteTest, BlockNoteTest) {
    Note note("Test Title", "Test Body", false, false);
    note.blockNote(true);
    note.editTitle("Attempt to edit");
    EXPECT_EQ(note.getTitle(), "Test Title");
    note.blockNote(false);
    note.editTitle("Edited Title");
    EXPECT_EQ(note.getTitle(), "Edited Title");
}
