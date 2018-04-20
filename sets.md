# Работа с множествами 

* По сравнению с оригинальным кодом были внесены изменения названий переменных и т.д.

```C++
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
// тип узел. Элемент связного списка
struct Node {
    // содержимое узла
    int data;
    // указатель на следующий элемент
    Node *next;
};

bool is_empty_set(Node *top) {
    return top == NULL;
}

void push(Node *&listTop, Node *&listEnd, int data) {
    // создали новый узел
    Node *newNode = new Node;
    // положили в него значение
    newNode->data = data;
    newNode->next = NULL;
    // если список был пустым
    if (is_empty_set(listTop)) {
        // начало и конец этого списка - один новый узел
        listTop = newNode;
        listEnd = newNode;
    } else {
        // если в списке уже были элемент, то
        // новый узел станет следующем после последнего
        listEnd->next = newNode;
        // и теперь последний это новый узел
        listEnd = newNode;
    }
}

// ищем в списке top узел, который содержит значение value
Node *find_node(Node *listTop, int value) {
    // начинаем с первого узла
    Node *current = listTop;
    // пока есть текущий и его значение не равно искомому
    while (current && (current->data) != value) {
        // идем дальше
        current = current->next;
    }
    // возвращаем последний интересный элемент
    // это либо элемент который хранит value, либо null
    return current;
}

// проверяем, входит ли value в список listTop
bool is_member(Node *listTop, int value) {
    return find_node(listTop, value) != NULL;
}

void create_set_from_file(ifstream &input,
                          Node *&listTop,
                          Node *&listEnd) {
    int value;

    listTop = NULL;
    listEnd = NULL;
    // если в файле НИЧО нет
    if (!input) {
        cout << "Can't open file!" << endl;
        exit(-1);
    }
    // считываем из файла значение, если считывание
    // прошло успешно, оператор >> вернет true
    while (input >> value) {
        // если этого значение в списке не было, кидаем
        // его в список
        if (!is_member(listTop, value)) {
            push(listTop, listEnd, value);
        }
    }
}

void sort(Node *topList, Node *endList) {
    int temp;
    // заводим два указателя
    Node *i, *j;
    // i-ый начинается с начала списка
    i = topList;
    // пока не дошли до конца

    // for (int i = 0; i < n;)
    while (i != endList) {
        // j всегда начинается со следующего после
        // i-го

        // for (int j = i; j < n;)
        j = i->next;
        // пока есть j-ый
        while (j) {
            // сравниваем два узла
            // и меняем значения при необходимости
            // if (a[i] > a[j]) { a[i] <-> a[j] }
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            // j++;
            j = j->next;

        }
        // i++
        i = i->next;
    }
}

void copy_sets(Node *sourceTopList, Node *sourceEndList,
               Node *&targetTopList, Node *&targetEndList) {
    targetTopList = NULL;
    targetEndList = NULL;

    Node *current = sourceTopList;
    while (current) {
        push(targetTopList, targetEndList, current->data);
        current = current->next;
    }
}

//topListC = topListA union topListB
void union_sets(Node *topListA, Node *endListA,
                Node *topListB, Node *endListB,
                Node *&topListC, Node *&endListC) {
    topListC = NULL;
    endListC = NULL;

    // копируем элементы из A в C
    copy_sets(topListA, endListA, topListC, endListC);

    Node *current = topListB;
    while (current) {
        // проверяем, не лежит ли элемент из B уже в C
        if (!is_member(topListC, current->data))
            // если не лежит, то кладем
            push(topListC, endListC, current->data);
        current = current->next;
    }
    sort(topListC, endListC);
}

// пересекаем множества A и B
void intersection_sets(Node *topListA, Node *endListA,
                       Node *topListB, Node *endListB,
                       Node *&topListC, Node *&endListC) {
    topListC = NULL;
    endListC = NULL;

    Node *current = topListB;
    while (current) {
        // проверяем, есть ли элемент из B в A
        if (is_member(topListA, current->data)) {
            // если есть - кладем в C
            push(topListC, endListC, current->data);
        }
        current = current->next;
    }
    sort(topListC, endListC);
}

// вычитание одного множества A из другого C
void subtraction_sets(Node *topListA, Node *endListA,
                      Node *topListB, Node *endListB,
                      Node *&topListC, Node *&endListC) {

    topListC = NULL;
    endListC = NULL;

    Node *current = topListA;
    while (current) {
        // проверяем, если элемента из A нет в B
        if (!is_member(topListB, current->data)) {
            // кидаем в C
            push(topListC, endListC, current->data);
        }
        current = current->next;
    }
    sort(topListC, endListC);
}

void symmetric_subtraction(Node *topListA, Node *endListA,
                           Node *topListB, Node *endListB,
                           Node *&topListC, Node *&endListC) {

    Node *topListD, *endListD, *topListE, *endListE;

    // D = A - B
    subtraction_sets(topListA, endListA,
                     topListB, endListB,
                     topListD, endListD);

    // E = B - A
    subtraction_sets(topListB, endListB,
                     topListA, endListA,
                     topListE, endListE);
    // C = D + E
    union_sets(topListD, endListD,
               topListE, endListE,
               topListC, endListC);

    sort(topListC, endListC);
}

void print_to_file(ofstream &output, Node *topList) {
    output << " { ";
    Node *current = topList;
    while (current) {
        output << current->data << " , ";
        current = current->next;
    }
    output << " } " << endl;
}

int main() {
    Node *topListA, *endListA,
            *topListB, *endListB,
            *topListC, *endListC;

    ifstream inputA("C:\\Users\\admin.WIN-IPM3OA3VQNQ\\ClionProjects\\Sets\\data1.txt");
    ifstream inputB("C:\\Users\\admin.WIN-IPM3OA3VQNQ\\ClionProjects\\Sets\\data2.txt");
    ofstream output("C:\\Users\\admin.WIN-IPM3OA3VQNQ\\ClionProjects\\Sets\\algebra_sets.txt");

    create_set_from_file(inputA, topListA, endListA);
    output << "ALGEBRA OF SETS" << endl;
    output << "set1: " << endl;
    print_to_file(output, topListA);
    inputA.close();

    create_set_from_file(inputB, topListB, endListB);
    output << "set2: " << endl;
    print_to_file(output, topListB);
    inputB.close();

    sort(topListA, endListA);
    output << "order set1=" << endl;
    print_to_file(output, topListA);

    sort(topListB, endListB);
    output << "order set2=" << endl;
    print_to_file(output, topListB);

    union_sets(topListA, endListA, topListB, endListB, topListC, endListC);
    output << "set3=se1 U set2: " << endl;
    print_to_file(output, topListC);

    intersection_sets(topListA, endListA, topListB, endListB, topListC, endListC);
    output << "set3=se1 ^ set2: " << endl;
    print_to_file(output, topListC);

    subtraction_sets(topListA, endListA, topListB, endListB, topListC, endListC);
    output << "set3=set1 - set2: " << endl;
    print_to_file(output, topListC);

    subtraction_sets(topListB, endListB, topListA, endListA, topListC, endListC);
    output << "set3=set2 - set1: " << endl;
    print_to_file(output, topListC);

    symmetric_subtraction(topListA, endListA, topListB, endListB, topListC, endListC);
    output << "set3=(set1 - set2)U(set2 - set1): " << endl;
    print_to_file(output, topListC);

    output.close();
    return 0;
}
```
