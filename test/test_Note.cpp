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


TEST(NoteTest, BlockNoteTest) {
    Note note("Test Title", "Test Body", false, false);
    note.blockNote(true);
    note.editTitle("Attempt to edit");
    EXPECT_EQ(note.getTitle(), "Test Title");
    note.blockNote(false);
    note.editTitle("Edited Title");
    EXPECT_EQ(note.getTitle(), "Edited Title");
}

/*TEST(NoteTest, EditSpecialTest) {
    Note note("Test Title", "Test Body", false, false);
    note.editSpecial(true);
    EXPECT_TRUE(note.special);
    note.editSpecial(false);
    EXPECT_FALSE(note.special);
}
*/