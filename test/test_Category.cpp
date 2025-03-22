#include "gtest/gtest.h"
#include "../Category.h"
#include "../Note.h"
#include "../CategoryCounter.h"
#include <sstream>
#include <iostream>

class CategoryTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup shared objects
        category_ = new Category("TestCategory");
        note1_ = new Note("Title1", "Body1+", false, false);
        note2_ = new Note("Title2-", "Body2", false, false);
        note3_ = new Note("TitleKey", "BodyKey+", false, false);
    }

    void TearDown() override {
        // Cleanup shared objects
        delete category_;
        delete note1_;
        delete note2_;
        delete note3_;
    }

    Category* category_;
    Note* note1_;
    Note* note2_;
    Note* note3_;
};

TEST_F(CategoryTest, Constructor) {
    // Redirect std::cout to capture output
    std::stringstream buffer;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(buffer.rdbuf());

    Category category("ConstructorTest");

    // Restore std::cout
    std::cout.rdbuf(old_cout_buffer);

    std::string output = buffer.str();
    ASSERT_NE(output.find("New category created successfully: ConstructorTest"), std::string::npos);
}

TEST_F(CategoryTest, AddNote) {
    category_->addNote(note1_);
    std::list<Note*> results = category_->findByKey("+");
    ASSERT_EQ(results.size(), 1);
    ASSERT_EQ(results.front(), note1_);
}

TEST_F(CategoryTest, RemoveNote) {
    category_->addNote(note1_);
    category_->addNote(note2_);
    category_->removeNote(note1_);
    std::list<Note*> results = category_->findByKey("Title1");
    ASSERT_EQ(results.size(), 0);
}

TEST_F(CategoryTest, FindByKeyTitle) {
    category_->addNote(note1_);
    category_->addNote(note2_);
    category_->addNote(note3_);
    std::list<Note*> results = category_->findByKey("-");
    ASSERT_EQ(results.size(), 1);
}

TEST_F(CategoryTest, FindByKeyBody) {
    category_->addNote(note1_);
    category_->addNote(note2_);
    category_->addNote(note3_);
    std::list<Note*> results = category_->findByKey("+");
    ASSERT_EQ(results.size(), 2);
}

TEST_F(CategoryTest, FindByKeyNoMatch) {
    category_->addNote(note1_);
    std::list<Note*> results = category_->findByKey("$");
    ASSERT_EQ(results.size(), 0);
}

TEST_F(CategoryTest, PrintCategory) {
    category_->addNote(note1_);
    category_->addNote(note2_);

    std::stringstream buffer;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(buffer.rdbuf());

    category_->printCategory();

    std::cout.rdbuf(old_cout_buffer);
    std::string output = buffer.str();

    ASSERT_NE(output.find("Category: TestCategory\n"), std::string::npos);
    ASSERT_NE(output.find("Title1\nBody1+\n"), std::string::npos);
    ASSERT_NE(output.find("Title2-\nBody2\n"), std::string::npos);
}

TEST_F(CategoryTest, NotifyAdd) {
    std::stringstream buffer;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(buffer.rdbuf());

    category_->Notify(true);
    std::cout.rdbuf(old_cout_buffer);

    std::string output = buffer.str();
    ASSERT_NE(output.find("TestCategory updated successfully, "), std::string::npos);
}

TEST_F(CategoryTest, NotifyRemove) {
    std::stringstream buffer;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(buffer.rdbuf());

    category_->Notify(false);

    std::cout.rdbuf(old_cout_buffer);
    std::string output = buffer.str();

    ASSERT_NE(output.find("TestCategory updated successfully, "), std::string::npos);
}

TEST_F(CategoryTest, Destructor) {
    std::stringstream buffer;
    std::streambuf* old_cout_buffer = std::cout.rdbuf(buffer.rdbuf());

    {
        Category tempCategory("TempCategory");
    }

    std::cout.rdbuf(old_cout_buffer);
    std::string output = buffer.str();

    ASSERT_NE(output.find("TempCategory deleted successfully"), std::string::npos);
}