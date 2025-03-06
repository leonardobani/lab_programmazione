//
// Created by yoga on 06/03/25.
//

#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>
#include <iostream>
#include "Note.h"
#include "CategoryCounter.h"

class Category{
    std::string name;
    std::list<Note*> list_;
    CategoryCounter delegatedCounter;

public:
    explicit Category(std::string newName): name(std::move(newName)) {
        std::cout << "New category created successfully: " << name << std::endl;
        delegatedCounter = CategoryCounter();
    }

    void Notify(const bool addOrRemove) {
        std::cout << name << " updated successfully, ";
        delegatedCounter.Update(addOrRemove);
    }

    void addNote(Note *newNote) {
        list_.push_back(newNote);
        Notify(true);
    }

    void removeNote(Note *newNote) {
        list_.remove(newNote);
        Notify(false);
    }

    ~Category() {
        std::cout << name << " deleted successfully" << std::endl;
    }

    void printCategory() const {
        std::cout << "Category: " << name << "\n";
        for (auto note : list_) {
            note->printNote();
        }
    }

};


#endif //CATEGORY_H
