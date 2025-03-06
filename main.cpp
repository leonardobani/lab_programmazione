#include "Category.h"
#include "Note.h"


int main() {
    auto ImportantNotes = Category("ImportantNotes");
    auto Animals = Category("Animals");
    auto Cats = Note("Meow", "fuck dogs", false, true);
    Animals.addNote(&Cats);
    ImportantNotes.addNote(&Cats);
    std::cout << "---------------------------------------------------------------------";
    ImportantNotes.printCategory();
    std::cout << "---------------------------------------------------------------------";

    auto Dogs = Note("Bau", "fuck cats", false, false);
    Animals.addNote(&Dogs);
    Animals.removeNote(&Cats);
    Cats.editBody("cats rocks");

}
