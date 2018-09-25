//
// Created by admin on 25.09.2018.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H


#include "Node.h"

class Queue {
private:
    Node *tail;
    Node *head;
    int count;
public:
    Queue();
    void push(int value);
    void print();
    void printReverse();
    int pop();
};


#endif //QUEUE_QUEUE_H
