//
// Created by admin on 13.11.2018.
//

#ifndef VIRTUALMETHODS_LETTERSANALYZER_H
#define VIRTUALMETHODS_LETTERSANALYZER_H


#include <cstring>
#include "TextFunction.h"

class ToLowerCaseFunction : public TextFunction {
public:
    void apply(char *text) override {
        for (int i = 0; i < strlen(text); i++) {
            if (text[i] >= 'A' && text[i] <= 'Z') {
                text[i] += 32;
            }
        }
    }
};


#endif //VIRTUALMETHODS_LETTERSANALYZER_H
