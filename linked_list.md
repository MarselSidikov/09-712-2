# Списки

* Список - тип данных, который представляет собой набор элементов, заданных в определенном порядке. 

## Набор операций над списком:

- ПоложитьВКонец(элемент)
- ПолучитьЭлемент(номер)
- ПоложитьВНачало(Элемент)
- УдалитьЭлемент(номер)
- УдалитьЭлемент(элемент)
- ЕстьЛи(элемент)
- Найти(элемент)

## Реализации списков

### Массив

* Поскольку элементы массива расположны в памяти друг за другом, доступ к этим элементам осуществляется очень быстро.

```
int a[] = {3, 4, 5, 6, 7};

[3][4][5][6][7]
 0  1  2  3  4

cout << a[2]; // что происходит?

// значение(адрес(a) + 2 * размер(int))
// а - адрес первого элемнта массива 
```

* Недостатки массива - поскольку массив занимает память блоком, его невозможно расширить, потому что можем задеть чужие данные.

Следовательно, вставка в конец, начало, в середину, переполнение массива - сложные для него ситуации, требующие сдвигов или создания нового массива.

### Связный список

* Связный список состоит из узлов.

Каждый узел хранит значение элемента и ссылку на следующий узел.

Такая организация элементов позволяет избежать затрат на увеличение массива и на сдвиги.

* Недостатки - нельзя получить быстро элемент по индексу.

```
[5] -> [6] -> [7] -> [8]
```
* Добавление в начало:

```
// создали узел
[6] -> NULL
[5] -> [6] -> [7] -> [8]
// перекинули ссылку с нового узла на первый узел исходного списка
[6] -> [5] -> [6] -> [7] -> [8]
```

* Как хранить связный список? - достаточно иметь первый элемент.

```C
#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int value;
    Node *next;
};


struct ArrayItem {
   Node *head;
   int count;
}

void reverse(Node *&first) {
    Node *previous = first;
    Node *current = first->next;
    Node *next = first->next->next;
    previous->next = NULL;

    /**
     * [10] -> [11] -> [12] -> [13] -> [14] -> [15]
     *  ^       ^       ^
     *  p       c       n
     *
     *  [10] <- [11] -> [12] -> [13] -> [14] -> [15]
     *          ^       ^       ^
     *         p       c        n
     */
    while (next != NULL) {
        current->next = previous;
        previous = current;
        current = next;
        next = next->next;
    }
    current->next = previous;
}

void print_linked_list(Node *first) {
    Node *current = first;

    while (current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }
}

// Карина, Лейсан, Никита
int get_by_index(Node *first, int index) {
    // TODO: реализовать получение элемента по индексу
}

// Карина, Лейсан, Никита
void remove_by_index(Node *&first, int index) {
   // TODO: реализовать удаление под индексу
}

// Карина, Лейсан, Никита
void add_to_begin(Node *&fisrt, int element) {
   // TODO: реализовать добавление в начало
}

// Карина, Лейсан, Никита
void add_to_end(Node *&first, int element) {
   // TODO: реализовать добавление в конец
}

// Ильгам, Рузия, Артем
Node* merge(Node *a, Node *b) {
   // TODO: реализовать слияние
}

// Ильгам, Рузия, Артем
Node* sort(Node *first) {
   // TODO: реализовать сортировку через слияние
   ArrayItem stack[32];
   // ...
}
int main() {

    Node *a = new Node;
    a->value = 10;
    Node *b = new Node;
    b->value = 11;
    Node *c = new Node;
    c->value = 12;
    Node *d = new Node;
    d->value = 13;
    Node *e = new Node;
    e->value = 14;
    Node *f = new Node;
    f->value = 15;
    Node *g = new Node;
    g->value = 16;
    Node *h = new Node;
    h->value = 17;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = NULL;

    reverse(a);
    print_linked_list(h);

    return 0;
}
```
