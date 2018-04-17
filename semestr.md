# Семетровая 

```C
#include <iostream>
#include <cstring>

const int START = 0;
const int ON_LETTER = 1;
const int ON_DIGIT = 2;
const int ERROR = 15;
const int END = 16;

bool isLetter(char character) {
    return character >= 'A' && character <= 'Z';
}

bool isDigit(char character) {
    return character >= '0' && character <= '9';
}

bool analyze(char input[]) {
    int state = 0;
    int length = strlen(input);

    for (int i = 0; i < length && state != ERROR; i++) {
        char currentChar = input[i];

        switch (state) {
            case START: {
                if (isLetter(currentChar)) {
                    state = ON_LETTER;
                } else if (isDigit(currentChar)) {
                    state = ON_DIGIT;
                } else {
                    state = ERROR;
                }
            }
                break;
            case ON_DIGIT: {
                if (isDigit(currentChar)) {
                    state = 0;
                } else {
                    state = ERROR;
                }
                break;
            }
            default: {
                state = ERROR;
            }
        }
    }

    return state == END;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```
