#include <iostream>
#include <utility>

//
//class Category {
//    int participants = 0;
//    Category(std::string name) { name = name;}
//};
//
class Note {
  public:
    std::string title;
    std::string body;
    std::string category;
    bool blocked = false;
    bool special = false;
    std::string const blocked_message = "please unlock before edit";

    Note(const std::string &newTitle, const std::string &newBody, const std::string &newCategory, const bool newBlocked, const bool newSpecial){title = newTitle; body = newBody; category = newCategory; blocked = newBlocked; special = newSpecial;};

    static void printErrorMessage(const std::string& error_message) {
        std::cout << "\033[1;31m" << error_message << "\033[0m\n\n";
    }

    void editTitle(const std::string &newTitle) {
        if(!blocked) {title = newTitle;}
        else{printErrorMessage(blocked_message);}
    }

    void editBody(const std::string &newBody) {
        if(!blocked){body = newBody;}
        else{printErrorMessage(blocked_message);}
    }

    void editCategory(const std::string &newCategory) {
        if(!blocked){category = newCategory;}
        else{printErrorMessage(blocked_message);}
    }

    void blockNote(const bool newBlocked){blocked = newBlocked;}

    void specialNote(const bool newSpecial){special = newSpecial;}

    void printNote() const {
        std::cout << "\033[1m" << title << "\033[0m";
        if(special){std::cout << "\033[33m" << "⭐" << "\033[0m";}
        if(blocked){std::cout << "\033[31m" << "🔒" << "\033[0m";}
        std::cout << "\n";
        std::cout << "\033[3m" <<category << "\033[0m\n";
        std::cout << body << "\n";
        std::cout << "\n";
    }

};


int main() {
    Note *Gatto;
    Gatto = new Note("Omaggio ai gatti", "belli i gatti", "animali", false, false);
    Gatto->printNote();
    Gatto->editTitle("Omaggio ai cani");
    Gatto->printNote();
    Gatto->blockNote(true);
    Gatto->editTitle("Omaggio ai pesci");
    Gatto->printNote();
    Gatto->specialNote(true);
    Gatto->printNote();
    return 0;
}
