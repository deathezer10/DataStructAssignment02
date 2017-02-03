#ifndef _QUEUE_H
#define _QUEUE_H

#include "Node.h"

//*******************************************************************//
// This is the declaration of the Queue class. Do not modify this file in any way
//*******************************************************************//

class Queue
{
public:
    Queue();
    virtual ~Queue();

    void enqueue(int data);
    int dequeue();
    size_t size();

protected:
    Node* front_;
    Node* back_;
};

#endif
