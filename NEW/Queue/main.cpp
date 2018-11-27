#include <iostream>
#include "Node.h"
#include "Queue.h"

using namespace std;
int main() {
    Queue *queue = new Queue();
    queue->push(1);
    queue->push(2);
    queue->push(3);
    queue->push(4);
    queue->push(5);
    queue->push(6);
    queue->print();
    cout << endl;
    queue->printReverse();
    cout << endl;
    cout << queue->pop() << endl;
    cout << queue->pop() << endl;
    cout << queue->pop() << endl;
    cout << queue->pop() << endl;
    queue->print();
}