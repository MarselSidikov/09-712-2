# Работа с двумерными массивами

```C
#include <iostream>

using namespace std;

int main() {
    // двумерный массив
    int a[5][5];
    // явная инициализация двумерного
    int b[3][3] = {{2, 3, 4},
                   {5, 4, 1},
                   {6, 7, 7}};

    // цикл по строкам
    for (int i = 0; i < 3; i++) {
        // цикл по столбцам
        for (int j = 0; j < 3; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        b[i][i] = 0;
    }
    cout << "after nulling" << endl;
    // цикл по строкам
    for (int i = 0; i < 3; i++) {
        // цикл по столбцам
        for (int j = 0; j < 3; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```