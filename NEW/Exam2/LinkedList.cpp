//
// Created by admin on 27.11.2018.
//

#include "LinkedList.h"

LinkedList::LinkedList() {
    // this - указатель на экземпляр, для которого был
    // произведен вызов функции/конструктора
    (*this).top = nullptr;
    this->end = nullptr;
    this->count = 0;
}

bool LinkedList::isEmpty() {
    return this->top == nullptr;
}

void LinkedList::add(int value) {
    Node *newNode = new Node(value);
    if (this->end != nullptr) {
        this->end->next = newNode;
    } else {
        this->top = newNode;
    }
    this->end = newNode;
}

void LinkedList::addToBegin(int value) {
    // TODO: реализовать
}

int LinkedList::size() {
    return this->count;
}

int LinkedList::get(int index) {
    // TODO: реализовать
}

void LinkedList::remove(int index) {
    // TODO: реализовать
}

