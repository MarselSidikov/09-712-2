//
// Created by admin on 25.09.2018.
//

#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H


class Node {
private:
    int value;
    Node *next;
    Node *previous;
public:
    Node(int value);

    int getValue();

    void setNext(Node *next);

    Node *getNext();

    void setPrevious(Node *previous);

    Node *getPrevious();
};


#endif //QUEUE_NODE_H
