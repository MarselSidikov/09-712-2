//
// Created by admin on 27.11.2018.
//

#ifndef EXAM2_LINKEDLIST_H
#define EXAM2_LINKEDLIST_H

#include <iostream>
#include "IList.h"

using namespace std;
// узел связного списка
struct Node
{
    // данные узла
    int data;
    // указатель на следующий элемент
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList : public IList {
protected:
    // указатель на начало списка
    Node *top;
    // указатель на конец списка
    Node *end;
    // количество элементов
    int count;
public:
    // конструктор - инициализирует созданный объект
    LinkedList();
    bool isEmpty() override;
    void add(int value) override ;
    void addToBegin(int value) override;
    int size() override;
    int get(int index) override;
    void remove(int index) override;
    bool contains(int value) override;
};


#endif //EXAM2_LINKEDLIST_H
