//
// Created by admin on 11.12.2018.
//

#ifndef EXAM2_IQUEUE_H
#define EXAM2_IQUEUE_H


class IQueue {
public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual bool contains(int value) = 0;
};


#endif //EXAM2_IQUEUE_H
