//
// Created by yoga on 06/03/25.
//

#ifndef CATEGORYCOUNTER_H
#define CATEGORYCOUNTER_H
#include <iostream>

class CategoryCounter {
    int counter = 0;
public:
    ~CategoryCounter() = default;
    void Update(const bool addOrRemove) {
        addOrRemove ? counter++ : counter--;
        std::cout << "current note number in category: " << counter << std::endl;
    };
};

#endif //CATEGORYCOUNTER_H
