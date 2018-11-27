//
// Created by admin on 13.11.2018.
//

#ifndef VIRTUALMETHODS_MAINTEXTPROCESSOR_H
#define VIRTUALMETHODS_MAINTEXTPROCESSOR_H


#include "TextFunction.h"

class MainTextProcessor {
public:
    void process(char text[], TextFunction* functions[], int count) {
        for (int i = 0; i < count; i++) {
            functions[i]->apply(text);
        }
    }
};


#endif //VIRTUALMETHODS_MAINTEXTPROCESSOR_H
