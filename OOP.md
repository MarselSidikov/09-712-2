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

## Модификатор static

Данный модификатор показывает, что метод, помеченный этим модификатором является статическим. То есть, его можно вызвать непосредственно из класса без создания объекта.

```C
static RationalNumber* multiply(RationalNumber *x, RationalNumber *y);

Вызов:

RationalNumber *c = RationalNumber::multiply(x, y);
```

## Перегрузка операторов

C++ дает возможность определить собственное поведение при использовании различных операторов для ваших классов. Например, перемножение двух дробей.

```C
RationalNumber operator*(RationalNumber y);
```

Таким образом, вы определили оператор умножения, в котором указали правый операнд. Заметьте, без использования указателей.

## Исходный код

* main.cpp

```C
#include <iostream>
#include "RationalNumber.h"
#include "LinkedList.h"

using namespace std;

int main() {
    RationalNumber x(10, 15);
    RationalNumber y(2, 5);
    // x->multiply(y);
    // RationalNumber *c = RationalNumber::multiply(x, y);
    RationalNumber c = x * y;
    c.print();

    cout << endl;

    LinkedList list;
    list.add(10);
    list.add(15);
    list.add(8);

    LinkedList list1;
    list1 + 4;
    list1 + 5;
    list1 + 6;

    list.print();
    cout << endl;
    list1.print();
    list + list1;
    cout << endl;
    list.print();
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
    RationalNumber(int a, int b);
    void setA(int a);
    void setB(int b);
    int getA();
    int getB();
    void print();
    void optimize();
    //static RationalNumber* multiply(RationalNumber *x, RationalNumber *y);
    RationalNumber operator*(RationalNumber y);
};

#endif //OOP_RATIONALNUMBER_H
```

* RationalNumber.cpp

```C
#include "RationalNumber.h"
#include <iostream>
using namespace std;

RationalNumber::RationalNumber(int a, int b) {
    this->setA(a);
    this->setB(b);
}

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
    return a;
}

int RationalNumber::getB() {
    return b;
}

void RationalNumber::optimize() {
    int n = nod(this->a, this->b);
    this->a = this->a / n;
    this->b = this->b / n;
}

void RationalNumber::print() {
    cout << this->a << '/' << this->b;
}

RationalNumber RationalNumber::operator*(RationalNumber y) {
    RationalNumber result(a * y.getA(),
    b * y.getB());
    result.optimize();
    return result;
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
    void operator+(int element);
    void operator+(LinkedList other);
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

void LinkedList::operator+(int element) {
    this->add(element);
}

void LinkedList::operator+(LinkedList other) {
    Node *current = other.top;
    while(current != nullptr) {
        this->add(current->getValue());
        current = current->getNext();
    }
}
```
