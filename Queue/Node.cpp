//
// Created by admin on 25.09.2018.
//

#include "Node.h"

Node::Node(int value) {
    this->value = value;
    this->next = nullptr;
}

int Node::getValue() {
    return this->value;
}

void Node::setNext(Node *next) {
    this->next = next;
}

Node *Node::getNext() {
    return this->next;
}

void Node::setPrevious(Node *previous) {
    this->previous = previous;
}

Node *Node::getPrevious() {
    return this->previous;
}
