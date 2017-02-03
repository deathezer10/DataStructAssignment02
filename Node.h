#ifndef _NODE_H
#define _NODE_H

//*******************************************************************//
// This is the declaration of the Node struct. Do not modify this file in any way
//*******************************************************************//

struct Node
{    
    // Default constructor
    Node() : data(0), next(0) {}
    // Constructor taking in a single int value
    explicit Node(int d) : data(d), next(0) {}
    // Destructor
    ~Node() {}  

    int data;
    Node* next;
};
#endif