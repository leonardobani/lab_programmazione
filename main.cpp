#include "Category.h"
#include "Note.h"


int main() {
    auto ImportantNotes = Category("ImportantNotes");
    auto Animals = Category("Animals");
    auto Cats = Note("Meow", "fuck dogs", false, true);
    std::string cats = Cats.printNote();
    std::cout << cats << std::endl;
    Animals.addNote(&Cats);
    ImportantNotes.addNote(&Cats);
    std::cout << "---------------------------------------------------------------------";
    ImportantNotes.printCategory();
    std::cout << "---------------------------------------------------------------------";

    auto Dogs = Note("Bau", "fuck cats", false, false);
    Animals.addNote(&Dogs);
    ImportantNotes.addNote(&Dogs);
    Animals.removeNote(&Cats);
    Cats.editBody("cats rocks");

    std::list catStuff = ImportantNotes.findByKey("cats");
    for (auto cat : catStuff) {
        std::cout << cat->printNote() << std::endl;
    }
}
