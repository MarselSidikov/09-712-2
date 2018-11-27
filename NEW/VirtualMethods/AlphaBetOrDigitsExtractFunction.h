//
// Created by admin on 13.11.2018.
//

#ifndef VIRTUALMETHODS_ALPHABETORDIGITSANALYZER_H
#define VIRTUALMETHODS_ALPHABETORDIGITSANALYZER_H


#include <cstring>
#include "TextFunction.h"

class AlphaBetOrDigitsExtractFunction : public TextFunction {
public:
    void apply(char *text) override {
        for (int i = 0; i < strlen(text); i++) {
            if (!(text[i] >= 'A' && text[i] <= 'Z' || text[i] >= 'a' && text[i] <= 'z' || text[i] >= '0' && text[i] <= '9')) {
                text[i] = ' ';
            }
        }
    }
};


#endif //VIRTUALMETHODS_ALPHABETORDIGITSANALYZER_H
