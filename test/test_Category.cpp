#include "gtest/gtest.h"
#include "../Category.h"
#include "../Note.h"
#include <sstream>
#include <iostream>

// Mock Note class for testing
class MockNote : public Note {
public:
    explicit MockNote(std::string text) : Note(text, "mock body", false, false) {}
    void printNote() const {
        std::cout << "MockNote: " << getText() << std::endl;
    }
    std::string getText() const {return title;}
};

TEST(CategoryTest, ConstructorAndDestructor) {
    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());

    {
        Category category("TestCategory");
        EXPECT_EQ(ss.str(), "New category created successfully: TestCategory\n");
        ss.str("");
    }

    EXPECT_EQ(ss.str(), "TestCategory deleted successfully\n");

    std::cout.rdbuf(old_cout_buffer);
}

TEST(CategoryTest, AddAndRemoveNote) {
    Category category("TestCategory");
    MockNote* note1 = new MockNote("Note 1");
    MockNote* note2 = new MockNote("Note 2");

    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());

    category.addNote(note1);
    EXPECT_TRUE(ss.str().find("TestCategory updated successfully, ") != std::string::npos);
    ss.str("");

    category.addNote(note2);
    EXPECT_TRUE(ss.str().find("TestCategory updated successfully, ") != std::string::npos);
    ss.str("");

    category.removeNote(note1);
    EXPECT_TRUE(ss.str().find("TestCategory updated successfully, ") != std::string::npos);
    ss.str("");

    category.removeNote(note2);
    EXPECT_TRUE(ss.str().find("TestCategory updated successfully, ") != std::string::npos);
    ss.str("");

    std::cout.rdbuf(old_cout_buffer);

    delete note1;
    delete note2;
}

TEST(CategoryTest, PrintCategory) {
    Category category("TestCategory");
    MockNote* note1 = new MockNote("Note 1");
    MockNote* note2 = new MockNote("Note 2");

    category.addNote(note1);
    category.addNote(note2);

    std::stringstream ss;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(ss.rdbuf());

    category.printCategory();

    std::string expectedOutput = "Category: TestCategory\n\x1B[1mNote 1\x1B[0m\nmock body\n\n\x1B[1mNote 2\x1B[0m\nmock body\n\n";
    EXPECT_EQ(ss.str(), expectedOutput);

    std::cout.rdbuf(old_cout_buffer);

    delete note1;
    delete note2;
}