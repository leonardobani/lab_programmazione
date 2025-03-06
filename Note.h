//
// Created by yoga on 06/03/25.
//

#ifndef NOTE_H
#define NOTE_H
#include <ostream>

#include "SpecialNotes.h"


class Note {
    std::string body;
    bool blocked;
    bool special;
    std::string const blocked_message = "please unlock before edit";
public:
    std::string title;


    Note(std::string newTitle, std::string newBody, const bool newBlocked, const bool newSpecial): title(std::move(newTitle)), body(std::move(newBody)), blocked(newBlocked), special(newSpecial) {
        std::cout << "New note created successfully" << std::endl;
        printNote();
    }

    static void printErrorMessage(const std::string& error_message) {
        std::cout << "\033[1;31m" << error_message << "\033[0m\n\n";
    }

    void editTitle(const std::string &newTitle) {
        if(!blocked) {
            title = newTitle;
            printNote();
        }
        else{printErrorMessage(blocked_message);}
    }

    void editBody(const std::string &newBody) {
        if(!blocked) {
            body = newBody;
            printNote();
        }
        else{printErrorMessage(blocked_message);}
    }

    void blockNote(const bool newBlocked){blocked = newBlocked;}

    void editSpecial(const bool newSpecial) {
        if (newSpecial != special) {
            //newSpecial ? SpecialNotes::addSpecialNote(this) : SpecialNotes::removeSpecialNote(this);
        }
        special = newSpecial;
    }

    void printNote() const {
        std::cout << "\033[1m" << title << "\033[0m";
        if(special){std::cout << "\033[33m" << "⭐" << "\033[0m";}
        if(blocked){std::cout << "\033[31m" << "🔒" << "\033[0m";}
        std::cout << "\n";
        std::cout << body << "\n";
        std::cout << "\n";
    }

};


#endif //NOTE_H
