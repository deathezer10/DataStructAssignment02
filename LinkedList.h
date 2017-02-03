#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include "Node.h"

//*******************************************************************//
// This is the declaration of the LinkedList class. Do not modify this file in any way
//*******************************************************************//

class LinkedList
{
public:
    LinkedList();
    virtual ~LinkedList();

    void push_front(int data);
    void push_back(int data);
    int pop_front();
    int pop_back();
    void insert_at(int pos, int data);
    int pop_at(int pos);
    size_t size();

protected:
    Node* head_;
};

#endif