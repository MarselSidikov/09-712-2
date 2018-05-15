# ООП

* Класс - абстрактный (пользовательский) тип данных.
* Объект - экземпляр класса

## struct и class

* struct - ключевое слово, используемое при объявлении нового типа-структура.
* Структура - набор разнотипных переменных
* Класс - это полноценный тип, экзепляры которого обладают состоянием и поведением

## ООП в C++

* Класс представлен двумя файлами - header-файл (файл с расширением h), заголовочный файл и файл с реализацией (.cpp)

## RationalNumber как структура

```C
#include <iostream>

using namespace std;
struct RationalNumber {
    int a;
    int b;
};

int nod(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    return a + b;
}

void optimize(RationalNumber *x) {
    int n = nod(x->a, x->b);
    x->a = x->a / n;
    x->b = x->b / n;
}

int main() {
    // в памяти будет создан экземпляр структуры
    // RationalNumber, а x - указатель на эту структуру
    RationalNumber *x = new RationalNumber;
    x->a = 10;
    x->b = 0;
    optimize(x);
    cout << x->a << '/' << x->b;
    return 0;
}
```

## Модификатор доступа private

* Данный модификатор доступа говорит классу, что его член не должен доступен извне.

## Члены класса

* Поля (состояние) - переменные, значения которых у каждого объекта свои

* Методы (поведение) - методы, которые можно вызвать из объекта.

## Исходный код

* main.cpp

```C
#include <iostream>
#include "RationalNumber.h"
#include "LinkedList.h"

using namespace std;

int main() {
    RationalNumber *x = new RationalNumber;
    x->setA(10);
    x->setB(15);
    x->optimize();
    x->print();

    LinkedList *list = new LinkedList;
    list->add(10);
    list->add(15);
    list->add(8);
    list->print();
    return 0;
}
```

* RationalNumber.h

```C
//
// Created by admin on 15.05.2018.
//

#ifndef OOP_RATIONALNUMBER_H
#define OOP_RATIONALNUMBER_H

// Заголовочный файл
// Здесь определяется новый тип
class RationalNumber {
private:
    // поля
    // конкретные значения полей
    // определяют состояние объекта
    int a;
    int b;
    int nod(int a, int b);
public:
    // методы доступа - только заголовки
    void setA(int a);
    void setB(int b);
    int getA();
    int getB();
    void print();
    void optimize();
};

#endif //OOP_RATIONALNUMBER_H

```

* RationalNumber.cpp

```C
#include "RationalNumber.h"
#include <iostream>
using namespace std;
void RationalNumber::setA(int a) {
    this->a = a;
}

void RationalNumber::setB(int b) {
    if (b != 0) {
        this->b = b;
    } else {
        this->b = 1;
    }
}

int RationalNumber::getA() {
    return this->a;
}

int RationalNumber::getB() {
    return this->b;
}

void RationalNumber::optimize() {
    int n = nod(this->a, this->b);
    this->a = this->a / n;
    this->b = this->b / n;
}

void RationalNumber::print() {
    cout << this->a << '/' << this->b;
}

int RationalNumber::nod(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    return a + b;
}
```

* Node.h

```C
//
// Created by admin on 15.05.2018.
//

#ifndef OOP_NODE_H
#define OOP_NODE_H

class Node {
private:
    int value;
    Node *next;
public:
    Node(int value);
    int getValue();
    Node* getNext();
    void setNext(Node *next);
};


#endif //OOP_NODE_H
```

* Node.cpp

```C
//
// Created by admin on 15.05.2018.
//

#include "Node.h"

Node::Node(int value) {
    this->value = value;
    this->next = nullptr;
}

int Node::getValue() {
    return this->value;
}

Node *Node::getNext() {
    return this->next;
}

void Node::setNext(Node *next) {
    this->next = next;
}
```

* LinkedList.h

```C
//
// Created by admin on 15.05.2018.
//

#ifndef OOP_LINKEDLIST_H
#define OOP_LINKEDLIST_H


#include "Node.h"

class LinkedList {
private:
    Node *top;
public:
    LinkedList();
    void add(int value);
    void print();
};


#endif //OOP_LINKEDLIST_H
```

* LinkedList.cpp

```C
//
// Created by admin on 15.05.2018.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

void LinkedList::add(int value) {
    Node *newNode = new Node(value);
    if (this->top == nullptr) {
        top = newNode;
    } else {
        newNode->setNext(this->top);
        this->top = newNode;
    }
}


void LinkedList::print() {
    Node *current = this->top;
    while (current != nullptr) {
        cout << current->getValue() << " ";
        current = current->getNext();
    }
}

LinkedList::LinkedList() {
    this->top = nullptr;
}
```
