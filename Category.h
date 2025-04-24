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
    virtual ~ISubject() = default;

    virtual void Attach(IObserver *observer) = 0;

    virtual void Detach(IObserver *observer) = 0;

    virtual void Notify(bool variable) = 0;
};

class Category : public ISubject {
private:
    std::string name;
    std::list<Note *> list_;
    CategoryCounter delegatedCounter;

public:
    void Attach(IObserver *observer) override {
    }

    void Detach(IObserver *observer) override {
    }

    explicit Category(std::string newName): name(std::move(newName)) {
        std::cout << "New category created successfully: " << name << std::endl;
        delegatedCounter = CategoryCounter();
    }

    //!sizes normal note and special
    int getSpecialSize() const;

    int getCategorySize() const {
        return list_.size();
    }


    void Notify(bool addOrRemove) override {
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

    ~Category() override {
        std::cout << name << " deleted successfully" << std::endl;
    }

    //! rimuove da titlolo (con il find by key)
    //! separare i metodi "lunghi", si ma tutti nello stesso file
    void removeNoteByTitle(const std::string &toDeleteNoteTitle);

    std::list<Note *> findByKeyTitle(const std::string &key) const;

    std::list<Note *> findByKeyBody(const std::string &key) const;

    std::list<Note *> findByKey(const std::string &key) const;
};


#endif //CATEGORY_H
