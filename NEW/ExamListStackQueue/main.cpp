#include <iostream>
#include "IList.h"
#include "LinkedList.h"
#include "IStack.h"
#include "StackListImpl.h"
#include "ArrayList.h"
#include "IQueue.h"
#include "QueueListImpl.h"

int main() {
    IList *linkedList = new LinkedList();
    IList *arrayList = new ArrayList();
    IStack *stack = new StackListImpl(linkedList);
    IQueue *queue = new QueueListImpl(arrayList);
    return 0;
}