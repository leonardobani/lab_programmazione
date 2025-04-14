//
// Created by yoga on 06/03/25.
//

#ifndef CATEGORYCOUNTER_H
#define CATEGORYCOUNTER_H
#include <iostream>

//!aggiungere interfce class

class IObserver {
public:
    virtual ~IObserver()= default;
    virtual void Update(bool variable) = 0;
};

class CategoryCounter final : public IObserver {
    int counter = 0;
public:
    ~CategoryCounter() override = default;
    void Update(const bool addOrRemove) override {
        addOrRemove ? counter++ : counter--;
        std::cout << "current note number in category: " << counter << std::endl;
    };
};

#endif //CATEGORYCOUNTER_H
