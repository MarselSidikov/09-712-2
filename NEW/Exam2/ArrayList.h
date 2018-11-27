//
// Created by admin on 27.11.2018.
//

#ifndef EXAM2_ARRAYLIST_H
#define EXAM2_ARRAYLIST_H


#include "IList.h"

class ArrayList : public IList {
    bool isEmpty() override;
    void add(int value) override ;
    void addToBegin(int value) override;
    int size() override;
    int get(int index) override;
    void remove(int index) override;
};


#endif //EXAM2_ARRAYLIST_H
