//
// Created by leo on 15/04/25.
//
#include "../Category.h"
int Category::getSpecialSize() const {
    int size = 0;
    for (const auto note : list_) {
        if (note->getSpecial()) {
            size++;
        }
    }
    return size;
}
