# Третья задача демо-варианта экзамена

```C
#include <iostream>
#include<iostream>
#include <climits>

using namespace std;
// новый тип - узел связного списка
struct Node {
    // содержимое узла
    int data;
    // указатель на следующий элемент
    Node *next;
};

// проверяем, пуст ли список
bool is_empty_list(Node *top) {
    return top == NULL;
}

// добавить элемент в начало списка
void push(Node *&top, int data) {
    Node *current;
    current = new Node;
    // считали значение текущего узла
    current->data = data;
    // сказали, что следующий узел, после текущего
    // это тот, который раньше был первым
    current->next = top;
    // теперь новый узел первый
    top = current;
}

// процедура создания списка, на вход передаем
// указатель на первый элемент списка
// важный момент - &, это значит
// что вы можете в процедуре изменить значение указателя
// и он поменяется в вызывающей подпрограмме
void create_list(Node *&top, int n) {
    top = NULL;
    int currentData;
    // на вход приняли количество узлов
    // следовательно организуем цикл по этому количеству
    for (int i = 0; i < n; i++) {
        cout << " enter current->data=";
        cin >> currentData;
        push(top, currentData);
    }
}

// создаем массив списков
void create_array_of_lists(Node **lists, int listsCount) {
    // количество элементов в каждом списке
    int n;
    // бежим по всем спискам
    for (int i = 0; i < listsCount; i++) {
        // считываем количество элементов в этом списке
        cout << "enter n=";
        cin >> n;
        // создаем i-ый список
        create_list(lists[i], n);
    }
}

void show_list(Node *top) {
    Node *current;
    current = top;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void show_array_of_lists(Node **lists, int listsCount) {
    int i;
    for (i = 0; i < listsCount; i++) {
        cout << " list[" << i << "]=" << endl;
        show_list(lists[i]);
    }
}

// EiAj a[i][j]>0
bool EA(Node **lists, int n) {
    Node *current;
    bool isListFind = false;
    // бежим по всем спискам пока не прошли все
    // или список не найден
    for (int i = 0; i < n && !isListFind; i++) {
        // полагаем что список не пустой и не содержит отриц элементов
        bool isCurrentListIsCorrect = true;
        // берем текущий список
        current = lists[i];
        // если список пустой
        if (is_empty_list(lists[i])) {
            isCurrentListIsCorrect = false;
        }
        // пока текущий список не кончился
        // и он не пустой и не содержит отриц элементов
        while (current && isCurrentListIsCorrect) {
            // проверяем текущий элемент списка
            if (current->data <= 0) {
                // как только нашли в нем отриц элемент
                // говорим что он не корректный
                isCurrentListIsCorrect = false;
            }
            // переходим
            current = current->next;
        }
        // запоминаем информацию по последнему просмотренному 
        // списку
        isListFind = isCurrentListIsCorrect;
    }
    return isListFind;
}

int max(Node *top) {
    int currentMax;
    Node *node;
    node = top;
    // если список пустой
    if (is_empty_list(top)) {
        // возвращаем минимаьно возможное значение int
        return INT_MIN;
    }
    // предполагаем что первый элемент списка
    // максимальный
    currentMax = node->data;
    // пока узел есть
    while (node) {
        // смотрим текущий узел, если его
        // значение больше, запоминаем его
        if (currentMax < node->data) {
            currentMax = node->data;
        }
        // идем дальше
        node = node->next;
    }
    // возвращаем значение максимума
    return currentMax;
}

int sum_max(Node **lists, int n) {
    int sumOfMax = 0;
    // бежим по всем спискам
    for (int i = 0; i < n; i++) {
        // если список есть
        if (lists[i]) {
            // суммируем его максимум со всей суммой
            sumOfMax = sumOfMax + max(lists[i]);
        }
    }
    return sumOfMax;
}

int is_prime(int x) {
    bool p = true;
    if (x <= 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int sum_primes_in_list(Node *top) {
    int sum = 0;
    Node *current = top;
    while (current) {
        if (is_prime(current->data)) {
            sum = sum + current->data;
        }
        current = current->next;
    }
    return sum;
}

int sum_primes_in_array_of_lists(Node **lists, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (lists[i]) {
            sum = sum + sum_primes_in_list(lists[i]);
        }
    }
    return sum;
}

int main() {
    int listsCount;
    Node **lists;
    cout << "enter lists count = ";
    cin >> listsCount;

    lists = new Node *[listsCount];

    create_array_of_lists(lists, listsCount);
    cout << " array of lists = " << endl;
    show_array_of_lists(lists, listsCount);
    int result;
    if (EA(lists, listsCount)) {
        result = sum_max(lists, listsCount);
    } else {
        result = sum_primes_in_array_of_lists(lists, listsCount);
    }
    cout << "result = " << result << endl;
}
```
