#include "DetectMemoryLeak.h"
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <queue>

using std::string;
using std::vector;
using std::list;
using std::map;
using std::stack;
using std::queue;

// DO NOT MODIFY ANY LINE ABOVE OR ADD EXTRA INCLUDES

/*! 
 *  \brief     DM2126 Assignment 2
 *  \details   Submit the whole solution, but only this file will be used to grade
 *  \author    <John Doe>
 *  \date      2015 
 *  \note      <Admin ID>
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList() 
{
}

LinkedList::~LinkedList()
{ 
}

void LinkedList::push_front(int data)
{
}

void LinkedList::push_back(int data)
{
}

int LinkedList::pop_front()
{
    return 0;
}

int LinkedList::pop_back()
{    
    return 0;
}

void LinkedList::insert_at(int pos, int data)
{    
}

int LinkedList::pop_at(int pos)
{
    return 0;
}

size_t LinkedList::size()
{
    return 0;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() 
{
}

Queue::~Queue()
{   
}

void Queue::enqueue(int data)
{   
}

int Queue::dequeue()
{
    return 0;
}

size_t Queue::size()
{
    return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack()
{

}

Stack::~Stack()
{
}

void Stack::push(int data)
{
}

int Stack::pop()
{
    return 0;
}

size_t Stack::size()
{
    return 0;
}



// Balanced parenthesis
bool Brackets(const string& input)
{
    return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results)
{
}