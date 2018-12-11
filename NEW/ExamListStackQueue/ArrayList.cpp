//
// Created by admin on 27.11.2018.
//

#include "ArrayList.h"

bool ArrayList::isEmpty() {
    return this->currentSize == 0;
}

void ArrayList::add(int value) {
    // TODO: реализовать
}

void ArrayList::addToBegin(int value) {
    // TODO: реализовать
}

int ArrayList::size() {
    return currentSize;
}

int ArrayList::get(int index) {
    // TODO: реализовать
}

void ArrayList::remove(int index) {
    // TODO: реализовать
}

bool ArrayList::contains(int value) {
    // TODO: реализовать
}

ArrayList::ArrayList() {
    this->maxSize = DEFAULT_SIZE;
    this->elements = new int[this->maxSize];
    this->currentSize = 0;
}
