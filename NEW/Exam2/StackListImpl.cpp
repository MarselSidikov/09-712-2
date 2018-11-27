//
// Created by admin on 27.11.2018.
//

#include "StackListImpl.h"

void StackListImpl::push(int value) {
    this->list->addToBegin(value);
}

int StackListImpl::pop() {
    int result = this->list->get(0);
    this->list->remove(0);
    return result;
}

StackListImpl::StackListImpl(IList *list) {
    this->list = list;
}
