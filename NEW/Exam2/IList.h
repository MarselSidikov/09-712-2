//
// Created by admin on 27.11.2018.
//

#ifndef EXAM2_LIST_H
#define EXAM2_LIST_H

class IList {
public:
    virtual void add(int value) = 0;
    virtual void addToBegin(int value) = 0;
    virtual int size() = 0;
    virtual int get(int index) = 0;
    virtual bool isEmpty() = 0;
    virtual void remove(int index) = 0;
};


#endif //EXAM2_LIST_H
