//
// Created by yoga on 06/03/25.
//

#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>
#include <iostream>
#include <list>

#include "Note.h"
#include "CategoryCounter.h"

class Category{
    std::string name;
    std::list<Note*> list_;
    CategoryCounter delegatedCounter;
    //TODO elenco note per sapere n speciali e n totale, risolvo quindi conflitto con special notes (da eliminare)

public:
    explicit Category(std::string newName): name(std::move(newName)) {
        std::cout << "New category created successfully: " << name << std::endl;
        delegatedCounter = CategoryCounter();
    }

    int getCategorySize() const {
        return list_.size();
    }

    int getSpecialSize() {
        int size = 0;
        for (auto note : list_) {
            if (note->getSpecial()) {
                size++;
            }
        }
        return size;
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
    //TODO rimuove da titlolo (con il find by key)
    void removeNoteByTitle(const std::string& toDeleteNoteTitle) {
        std::list<Note*> toDeleteList = findByKeyTitle(toDeleteNoteTitle);

        for (auto note : toDeleteList) {
            removeNote(note);
        }
    }

    ~Category() {
        std::cout << name << " deleted successfully" << std::endl;
    }

    std::list<Note*> findByKeyTitle(const std::string& key) {
        std::list<Note*> results;

        for (Note* Note : list_) {
            std::string noteTitle = Note->getTitle();

            if (noteTitle.find(key) != std::string::npos) {
                results.push_back(Note);
            }
        }
        return results;
    }

    std::list<Note*> findByKey(const std::string& key) {
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

    void printCategory() const {
        std::cout << "Category: " << name << "\n";
        for (auto note : list_) {
            std::string noteText = note->printNote();
            std::cout << noteText << "\n";
        }
    }

};


#endif //CATEGORY_H
