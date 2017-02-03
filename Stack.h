#ifndef _STACK_H
#define _STACK_H

#include "Node.h"

//*******************************************************************//
// This is the declaration of the Stack Class. Do not modify this file in any way
//*******************************************************************//

class Stack
{
public:
    Stack();
    virtual ~Stack();

    void push(int data);
    int pop();
    size_t size();

protected:
    Node* top_;
};

#endif