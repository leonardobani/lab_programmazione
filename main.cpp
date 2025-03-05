#include <iostream>
#include <list>
#include <utility>

class Note;
class Category;
class CategoryCounter;
class SpecialCategory;


class SpecialCategory {

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

};
std::list<Note*> SpecialCategory::specialList;

class Note {
public:
    std::string title;
    std::string body;
    bool blocked;
    bool special;
    std::string const blocked_message = "please unlock before edit";

    Note(std::string newTitle, std::string newBody, const bool newBlocked, bool newSpecial): title(std::move(newTitle)), body(std::move(newBody)), blocked(newBlocked), special(newSpecial) {
        std::cout << "New note created successfully" << std::endl;
        printNote();
    }

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

    void blockNote(const bool newBlocked){blocked = newBlocked;}

    void editSpecial(const bool newSpecial) {

        if (newSpecial != special) {
            newSpecial ? SpecialCategory::addSpecialNote(this) : SpecialCategory::removeSpecialNote(this);
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

class CategoryCounter {
    int counter = 0;
public:
    ~CategoryCounter() = default;
    void Update(const bool addOrRemove) {
        addOrRemove ? counter++ : counter--;
        std::cout << "current note number in category: " << counter << std::endl;
    };
};

class Category{
    std::string name;
    std::list<Note*> list_;
    CategoryCounter delegatedCounter;

public:
    explicit Category(std::string newName): name(std::move(newName)) {
        std::cout << "New category created successfully: " << name << std::endl;
        delegatedCounter = CategoryCounter();
    }

    void Notify(bool addOrRemove) {
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

};

int main() {
    auto Animals = Category("Animals");
    auto Cats = Note("Meow", "fuck dogs", false, true);
    Animals.addNote(&Cats);
    auto Dogs = Note("Bau", "fuck cats", false, false);
    Animals.addNote(&Dogs);
    Animals.removeNote(&Cats);
    Cats.editBody("cats rocks");
}
