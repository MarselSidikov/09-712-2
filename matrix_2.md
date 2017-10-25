# Поиск минимума каждой строки

```C
#include <iostream>

using namespace std;

const int ROWS_COUNT = 3;
const int COLUMNS_COUNT = 3;
int main() {
    int matrix[ROWS_COUNT][COLUMNS_COUNT] = { {2, 4, 5},
                         {4, 1, 5},
                         {2, -9, 1}};

    for (int i = 0; i < ROWS_COUNT; i++) {
        // на i-ой строке предполагаем, что
        // первый элемент этой строки минимальный
        int min = matrix[i][0];
        for (int j = 0; j < COLUMNS_COUNT; j++) {
            if (min > matrix[i][j]) {
                min = matrix[i][j];
            }
        }
        cout << "min in " << i << " is " << min << endl;
    }
    return 0;
}
```