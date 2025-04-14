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

class ISubject {
    public:
        virtual ~ISubject()= default;
        virtual void Attach(IObserver *observer) = 0;
        virtual void Detach(IObserver *observer) = 0;
        virtual void Notify(bool variable) = 0;
};

class Category : public ISubject {
    std::string name;
    std::list<Note*> list_;
    CategoryCounter delegatedCounter;

public:
    void Attach (IObserver *observer) override {};
    void Detach (IObserver *observer) override {};

    explicit Category(std::string newName): name(std::move(newName)) {
        std::cout << "New category created successfully: " << name << std::endl;
        delegatedCounter = CategoryCounter();
    }


    //!sizes normal note and special

    int getCategorySize() const {
        return list_.size();
    }

    int getSpecialSize() const {
        int size = 0;
        for (const auto note : list_) {
            if (note->getSpecial()) {
                size++;
            }
        }
        return size;
    }

    void Notify(const bool addOrRemove) override {
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

    //! rimuove da titlolo (con il find by key)
    void removeNoteByTitle(const std::string& toDeleteNoteTitle) {
        const std::list<Note*> toDeleteList = findByKeyTitle(toDeleteNoteTitle);

        for (const auto note : toDeleteList) {
            removeNote(note);
        }
    }

    ~Category() override {
        std::cout << name << " deleted successfully" << std::endl;
    }

    std::list<Note*> findByKeyTitle(const std::string& key) const {
        std::list<Note*> results;

        for (Note* Note : list_) {
            std::string noteTitle = Note->getTitle();

            if (noteTitle.find(key) != std::string::npos) {
                results.push_back(Note);
            }
        }
        return results;
    }

    std::list<Note*> findByKeyBody(const std::string& key) const {
        std::list<Note*> results;

        for (Note* Note : list_) {
            std::string noteBody = Note->getBody();

            if (noteBody.find(key) != std::string::npos) {
                results.push_back(Note);
            }
        }
        return results;
    }

    std::list<Note*> findByKey(const std::string& key) const {
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
        for (const auto note : list_) {
            std::string noteText = note->printNote();
            std::cout << noteText << "\n";
        }
    }

};


#endif //CATEGORY_H
