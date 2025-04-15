//
// Created by leo on 15/04/25.
//
#include "../Category.h"
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