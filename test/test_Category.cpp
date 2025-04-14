#include "gtest/gtest.h"
#include "../Category.h"
#include "../Note.h"
#include <memory>

TEST(CategoryTest, Constructor) {
    const Category category("Test Category");
    ASSERT_EQ(category.getCategorySize(), 0);
    ASSERT_EQ(category.getSpecialSize(), 0);
}

TEST(CategoryTest, AddNote) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Body 1", false, false);
    category.addNote(note1.get());
    ASSERT_EQ(category.getCategorySize(), 1);
    ASSERT_EQ(category.getSpecialSize(), 0);
}

TEST(CategoryTest, AddSpecialNote) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Body 1", false, true);
    category.addNote(note1.get());
    ASSERT_EQ(category.getCategorySize(), 1);
    ASSERT_EQ(category.getSpecialSize(), 1);
}

TEST(CategoryTest, RemoveNote) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Body 1", false, false);
    category.addNote(note1.get());
    ASSERT_EQ(category.getCategorySize(), 1);
    category.removeNote(note1.get());
    ASSERT_EQ(category.getCategorySize(), 0);
}

TEST(CategoryTest, RemoveNonExistingNote) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Body 1", false, false);
    const auto note2 = std::make_unique<Note>("Title 2", "Body 2", false, false);
    category.addNote(note1.get());
    category.removeNote(note2.get());
    ASSERT_EQ(category.getCategorySize(), 1);
}

TEST(CategoryTest, RemoveNoteByTitleExisting) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Body 1", false, false);
    const auto note2 = std::make_unique<Note>("Another Title", "Some body", false, true);
    category.addNote(note1.get());
    category.addNote(note2.get());
    category.removeNoteByTitle("Title 1");
    ASSERT_EQ(category.getCategorySize(), 1);
    ASSERT_EQ(category.getSpecialSize(), 1);
}

TEST(CategoryTest, RemoveNoteByTitleNonExisting) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Body 1", false, false);
    const auto note2 = std::make_unique<Note>("Another Title", "Some body", false, true);
    category.addNote(note1.get());
    category.addNote(note2.get());
    category.removeNoteByTitle("NonExistent");
    ASSERT_EQ(category.getCategorySize(), 2);
    ASSERT_EQ(category.getSpecialSize(), 1);
}

TEST(CategoryTest, FindByKeyTitleFound) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Test Title", "Body 1", false, false);
    const auto note2 = std::make_unique<Note>("Another Title", "Test Body", true, false);
    category.addNote(note1.get());
    category.addNote(note2.get());
    const std::list<Note*> results = category.findByKeyTitle("Test");
    ASSERT_EQ(results.size(), 1);
    ASSERT_EQ(results.front()->getTitle(), "Test Title");
}

TEST(CategoryTest, FindByKeyTitleNotFound) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Body 1", false, false);
    category.addNote(note1.get());
    const std::list<Note*> results = category.findByKeyTitle("NonExistent");
    ASSERT_TRUE(results.empty());
}

TEST(CategoryTest, FindByKeyBodyFound) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Test Body", false, false);
    const auto note2 = std::make_unique<Note>("Another Title", "Some Body", true, false);
    category.addNote(note1.get());
    category.addNote(note2.get());
    const std::list<Note*> results = category.findByKeyBody("Test");
    ASSERT_EQ(results.size(), 1);
    ASSERT_EQ(results.front()->getBody(), "Test Body");
}

TEST(CategoryTest, FindByKeyBodyNotFound) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Body 1", false, false);
    category.addNote(note1.get());
    const std::list<Note*> results = category.findByKeyBody("NonExistent");
    ASSERT_TRUE(results.empty());
}

TEST(CategoryTest, FindByKeyFoundInTitle) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Test Title", "Body 1", false, false);
    category.addNote(note1.get());
    const std::list<Note*> results = category.findByKey("Test");
    ASSERT_EQ(results.size(), 1);
    ASSERT_EQ(results.front()->getTitle(), "Test Title");
}

TEST(CategoryTest, FindByKeyFoundInBody) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Test Body", false, false);
    category.addNote(note1.get());
    const std::list<Note*> results = category.findByKey("Test");
    ASSERT_EQ(results.size(), 1);
    ASSERT_EQ(results.front()->getBody(), "Test Body");
}

TEST(CategoryTest, FindByKeyNotFound) {
    Category category("Test Category");
    const auto note1 = std::make_unique<Note>("Title 1", "Body 1", false, false);
    category.addNote(note1.get());
    const std::list<Note*> results = category.findByKey("NonExistent");
    ASSERT_TRUE(results.empty());
}
