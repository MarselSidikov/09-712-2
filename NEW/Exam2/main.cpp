#include <iostream>
#include "IList.h"
#include "LinkedList.h"
#include "IStack.h"
#include "StackListImpl.h"

int main() {
    IList *list = new LinkedList();
    IStack *stack = new StackListImpl(list);
    return 0;
}