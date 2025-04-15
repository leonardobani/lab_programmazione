#include "../Category.h"
//
// Created by leo on 15/04/25.
//
void Category::removeNoteByTitle(const std::string &toDeleteNoteTitle) {
    const std::list<Note *> toDeleteList = findByKeyTitle(toDeleteNoteTitle);

    for (const auto note: toDeleteList) {
        removeNote(note);
    }
}
