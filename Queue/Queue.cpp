//
// Created by admin on 25.09.2018.
//

#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    this->tail = nullptr;
    this->count = 0;
}

void Queue::push(int value) {
    Node *newNode = new Node(value);
    if (this->tail == nullptr) {
        this->tail = newNode;
        this->head = newNode;
    } else {
        newNode->setNext(this->tail);
        this->tail->setPrevious(newNode);
        this->tail = newNode;
    }
    count++;
}

void Queue::print() {
    cout << "end -> ";
    Node *currentNode = this->tail;
    for (int i = 0; i < this->count; i++) {
        cout << currentNode->getValue() << " ";
        currentNode = currentNode->getNext();
    }
    cout << " -> begin";
}

void Queue::printReverse() {
    cout << "begin <- ";
    Node *currentNode = this->head;
    for (int i = 0; i < this->count; i++) {
        cout << currentNode->getValue() << " ";
        currentNode = currentNode->getPrevious();
    }
    cout << " <- end";
}

int Queue::pop() {
    if (this->count != 0) {
        int valueFromQueue = this->head->getValue();
        Node *temp = this->head;
        this->head = this->head->getPrevious();
        delete(temp);
        count--;
        return valueFromQueue;
    } else {
        throw "Empty queue!";
    }
}
