//
// Created by leo on 24/04/25.
//
#include "Category.h"

std::list<Note*> Category::findByKey(const std::string& key) const {
    std::list<Note*> results;

    for (Note* Note : list_) {
        std::string noteTitle = Note->getTitle();
        std::string noteBody = Note->getBody();

        if (noteTitle.find(key) != std::string::npos || noteBody.find(key) != std::string::npos) {
            results.push_back(Note);
        }
    }
    return results;
}

std::list<Note*> Category::findByKeyBody(const std::string& key) const {
    std::list<Note*> results;

    for (Note* Note : list_) {
        std::string noteBody = Note->getBody();

        if (noteBody.find(key) != std::string::npos) {
            results.push_back(Note);
        }
    }
    return results;
}


std::list<Note*> Category::findByKeyTitle(const std::string& key) const {
    std::list<Note*> results;

    for (Note* Note : list_) {
        if (std::string noteTitle = Note->getTitle(); noteTitle.find(key) != std::string::npos) {
            results.push_back(Note);
        }
    }
    return results;
}

int Category::getSpecialSize() const {
    int size = 0;
    for (const auto note : list_) {
        if (note->getSpecial()) {
            size++;
        }
    }
    return size;
}

void Category::removeNoteByTitle(const std::string &toDeleteNoteTitle) {
    const std::list<Note *> toDeleteList = findByKeyTitle(toDeleteNoteTitle);

    for (const auto note: toDeleteList) {
        removeNote(note);
    }
}