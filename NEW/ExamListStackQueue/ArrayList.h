//
// Created by admin on 27.11.2018.
//

#ifndef EXAM2_ARRAYLIST_H
#define EXAM2_ARRAYLIST_H


#include "IList.h"

const int DEFAULT_SIZE = 10;
const double CAPACITY_VALUE = 1.5;
class ArrayList : public IList {
private:
    int *elements;
    int maxSize;
    int currentSize;
public:
    ArrayList();
    bool isEmpty() override;
    void add(int value) override ;
    void addToBegin(int value) override;
    int size() override;
    int get(int index) override;
    void remove(int index) override;
    bool contains(int value) override;
};


#endif //EXAM2_ARRAYLIST_H
