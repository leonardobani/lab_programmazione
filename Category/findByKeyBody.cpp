//
// Created by leo on 15/04/25.
//
#include "../Category.h"
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