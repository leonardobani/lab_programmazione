//
// Created by yoga on 06/03/25.
//

#ifndef SPECIALNOTES_H
#define SPECIALNOTES_H

#include "Note.h"
#include <list>
#include <iostream>

class Note;

class SpecialNotes {
    static std::list<Note*> specialList;
public:
    static void addSpecialNote(Note* newNote) {
        specialList.push_back(newNote);
        std::cout << "Note added to SpecialCategory\n";
    }

    static void removeSpecialNote(Note* noteToRemove) {
        specialList.remove(noteToRemove);
        std::cout << "Note removed from SpecialCategory\n";
    }

    static void printAllSpecialNotes() {
        for (auto note : specialList) {
            //note->printNote();
        }
    }

};

#endif //SPECIALNOTES_H
