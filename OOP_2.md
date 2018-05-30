# Наследование

## Второй(третий) принцип ООП

* Позволяет избежать дублирования кода на уровне классов. 

### Функции и процедуры позволяют избежать дублирования кода на уровне алгоритмов и последовательностей действий

* Наследование - механизм ООП, который позволяет объектам классов-потомков переопределять и копировать поведение и состояние объектов классов-предков.

## Наследование в C++

1) Определить класс предок со всеми необходимыми полями, конструкторами и методами.

```C
//
// Created by admin on 30.05.2018.
//

#ifndef INHERITANCE_COMPLEXNUMBER_H
#define INHERITANCE_COMPLEXNUMBER_H


class ComplexNumber {
protected:
	// поля класса
    double re;
    double im;
public:
	// конструктор, принимающий на вход два параметра
    ComplexNumber(double re, double im);
    // методы класса
    double calcModule();
    void print();
};


#endif //INHERITANCE_COMPLEXNUMBER_H
```

2) Заметим, что те поля, видимость которых мы хотим обеспечить в потомке мы помечаем как protected

3) Описываем реализацию класса-предка

```C
//
// Created by admin on 30.05.2018.
//

#include "ComplexNumber.h"
#include <cmath>
#include <iostream>
using namespace std;

ComplexNumber::ComplexNumber(double re, double im) {
    this->re = re;
    this->im = im;
}

double ComplexNumber::calcModule() {
    return sqrt(this->re * this->re +
    this->im * this->im);
}

void ComplexNumber::print() {
    cout << re << "+" << im << "i" << endl;
}
```

4) Описываем заголовочный файл класса-потомка, с указанием того, что наш потомок является потомком класса-предка через ':'

```C
//
// Created by admin on 30.05.2018.
//

#ifndef INHERITANCE_QUATERNION_H
#define INHERITANCE_QUATERNION_H

#include "ComplexNumber.h"

class Quaternion : public ComplexNumber {
private:
	// поля класса потомка (поля класса-предка будут скопированы автоматически, поэтому их описывать не нужно)
    double im2;
    double im3;
public:
    Quaternion(double re, double im,
    double im2, double im3);
    void print();
    double calcModule();
};


#endif //INHERITANCE_QUATERNION_H
```

5) При наследовании автоматически копируется реализация методов класса-предка. Если мы хотим описать свою реализацию данных методов (переопределить метод) мы должны их заново описать в классе потомке и указать их реализациюю в CPP-файле

```C
//
// Created by admin on 30.05.2018.
//

#include "Quaternion.h"
#include <cmath>
#include <iostream>
using namespace std;

Quaternion::Quaternion(double re, double im, double im2, double im3)
        : ComplexNumber(re, im){
    this->im2 = im2;
    this->im3 = im3;
}

void Quaternion::print() {
    cout << re << "+"
         << im << "i" << "+"
         << im2 << "j" << "+"
                       << im3 << "k" << endl;
}

double Quaternion::calcModule() {
    return sqrt(this->re * this->re +
    this->im * this->im + this->im2 * this->im2
    + this->im3 * this->im3);
}
```

6) Проверить код в Main

```C
#include <iostream>
#include "Quaternion.h"
#include "ComplexNumber.h"
using namespace std;
int main() {
    ComplexNumber *a = new ComplexNumber(5, 6);
    cout << a->calcModule() << endl;
    a->print();

    Quaternion *q = new Quaternion(5, 6, 3, 4);
    cout << q->calcModule() << endl;
    q->print();

}
```

## Механизм восходящего преобразования

* Пусть есть класс A - предок, и есть классы B, C, D - потомки.

* Тогда, можно объявить ссылочную переменую типа A* a, и ей присваивать объекты классов-потомков.

* Благодаря этому вы можете иметь коллекцию указателей типа A*, но при этом каждый из указателей может указывать на конкретный объект классов B, C или D

* И вы можете работать с коллекцией объектов разных типов таким образом, будто это объекты одного типа A

* Это третий(четвертый) принцип ООП - полиморфизм.

```C
//
// Created by admin on 30.05.2018.
//

#ifndef INHERITANCE2_SHAPE_H
#define INHERITANCE2_SHAPE_H

class Shape {
public:
    virtual double calcArea() = 0;
};


#endif //INHERITANCE2_SHAPE_H
```

```C
//
// Created by admin on 30.05.2018.
//

#ifndef INHERITANCE2_RECTANGLE_H
#define INHERITANCE2_RECTANGLE_H


#include "Shape.h"

class Rectangle : public Shape {
protected:
    int height;
    int weight;
public:
    Rectangle(int weight, int height);
    double calcArea();
};


#endif //INHERITANCE2_RECTANGLE_H
```

```C
//
// Created by admin on 30.05.2018.
//

#include "Rectangle.h"

double Rectangle::calcArea() {
    return this->height * this->weight;
}

Rectangle::Rectangle(int weight, int height) {
    this->weight = weight;
    this->height = height;
}
```

```C
//
// Created by admin on 30.05.2018.
//

#ifndef INHERITANCE2_ELLIPSE_H
#define INHERITANCE2_ELLIPSE_H


#include "Shape.h"

class Ellipse : public Shape {
protected:
    int radius1;
    int radius2;
public:
    Ellipse(int radius1, int radius2);
    double calcArea();
};


#endif //INHERITANCE2_ELLIPSE_H
```

```C
//
// Created by admin on 30.05.2018.
//

#include "Ellipse.h"
#include <cmath>
Ellipse::Ellipse(int radius1, int radius2) {
    this->radius1 = radius1;
    this->radius2 = radius2;
}

double Ellipse::calcArea() {
    return M_PI * radius1 * radius2;
}
```

```C
#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Ellipse.h"

using namespace std;
int main() {
    // восходящее преобразование
//    Shape *rectangle = new Rectangle(5, 2);
//    Shape *ellipse = new Ellipse(3, 2);
//    cout << rectangle->calcArea() << endl;
//    cout << ellipse->calcArea();
    Rectangle *a = new Rectangle(2, 3);
    Rectangle *b = new Rectangle(4, 2);
    Ellipse *c = new Ellipse(1, 2);
    Ellipse *d = new Ellipse(4, 1);

    Shape* shapes[] = {a, b, c, d};
    for (int i = 0; i < 4; i++) {
        cout << shapes[i]->calcArea() << endl;
    }

    return 0;
}
```
