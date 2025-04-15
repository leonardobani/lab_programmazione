#include "../Category.h"
//
// Created by leo on 15/04/25.
//
std::list<Note*> Category::findByKeyTitle(const std::string& key) const {
    std::list<Note*> results;

    for (Note* Note : list_) {
        if (std::string noteTitle = Note->getTitle(); noteTitle.find(key) != std::string::npos) {
            results.push_back(Note);
        }
    }
    return results;
}