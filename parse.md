# Преобразование массива цифр в число

```C
#include <iostream>
using namespace std;

int parse(char digits[], int N) {
    int x = 0;
    int t = 1;

    for (int i = N - 1; i >= 0; i--) {
        x = x + (digits[i] - '0') * t;
        t = t * 10;
    }

    return x;
}
int main() {
    char digits[] = "13879";
    int N = 5;

    int result = parse(digits, N);
    cout << result;
}
```