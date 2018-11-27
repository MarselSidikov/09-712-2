# Сортировка слиянием

```C
#include <iostream>
using namespace std;

const int N = 16;
int *helpArray = new int[N];


// процедура сливает две упорядоченные половинки массива
// в одну упорядоченную
// array[lower...middle] и array[middle + 1...higher)
void merge(int *array, int lower, int middle, int higher) {

    // в вспомогательный массив копируем интересующие нас значения
    for (int i = lower; i <= higher; i++) {
        helpArray[i] = array[i];
    }

    int i = lower, j = middle + 1;
    for (int current = lower; current <= higher; current++) {
        if (i > middle) {
            array[current] = helpArray[j];
            j++;
        } else if (j > higher) {
            array[current] = helpArray[i];
            i++;
        } else if (helpArray[j] < helpArray[i]) {
            array[current] = helpArray[j];
            j++;
        } else {
            array[current] = helpArray[i];
            i++;
        }
    }
}

// функция сортировки массива в границах [lower...higher]
void sort(int *array, int lower, int higher) {
    // останавливаем выполнение процедуры, если левая граница перевалила за правую
    if (higher <= lower) {
        return;
    }
    // вычисляем центр
    int middle = lower + (higher - lower) / 2;
    // сортируем левую половинку
    sort(array, lower, middle);
    // сортируем правую половинку
    sort(array, middle + 1, higher);
    // сливаем обе половинки
    merge(array, lower, middle, higher);
}

int main() {
    int myArray[] = {4, -10, 11, 45, 0, -23, 35, 62, 11, 0, -9, 11, -3, 4, 5, 1};
    sort(myArray, 0, N);
    for (int i = 0; i < N; i++) {
        cout << myArray[i] << ' ';
    }
}
```
