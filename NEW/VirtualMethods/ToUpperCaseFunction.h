//
// Created by admin on 13.11.2018.
//

#ifndef VIRTUALMETHODS_TOUPPERCASEFUNCTION_H
#define VIRTUALMETHODS_TOUPPERCASEFUNCTION_H


#include <cstring>
#include "TextFunction.h"

class ToUpperCaseFunction : public TextFunction {
public:
    void apply(char *text) override {
        for (int i = 0; i < strlen(text); i++) {
            if (text[i] >= 'a' && text[i] <= 'z') {
                text[i] -= 32;
            }
        }
    }
};


#endif //VIRTUALMETHODS_TOUPPERCASEFUNCTION_H
