//
// Created by admin on 11.12.2018.
//

#ifndef EXAM2_QUEUELISTIMPL_H
#define EXAM2_QUEUELISTIMPL_H


#include "IQueue.h"
#include "IList.h"

class QueueListImpl : public IQueue {
private:
    IList *list;
public:
    QueueListImpl(IList *list);
    void push(int value) override;
    int pop() override;
    bool contains(int value) override;
};


#endif //EXAM2_QUEUELISTIMPL_H
