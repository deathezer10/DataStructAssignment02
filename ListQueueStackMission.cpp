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
 *  \author    <Ong Hui Sheng>
 *  \date      2017
 *  \note      <160212S>
 */

//*******************************************************************//
// Linked list stuff
//*******************************************************************//
LinkedList::LinkedList() {
	head_ = 0;
}

LinkedList::~LinkedList() {
	// Delete existing nodes
	while (head_) {
		Node* old = head_;
		head_ = head_->next;
		delete old;
	}
}

void LinkedList::push_front(int data) {

	Node* newNode = new Node(data);

	if (!head_) { // empty
		head_ = newNode;
	}
	else {
		// swap the head with new node
		newNode->next = head_;
		head_ = newNode;
	}
}

void LinkedList::push_back(int data) {
	Node* newNode = new Node(data);

	if (!head_) {
		head_ = newNode;
	}
	else {
		Node* curr = head_;

		// traverse to the end and insert the new node 
		while (curr->next) {
			curr = curr->next;
		}

		curr->next = newNode;
	}
}

int LinkedList::pop_front() {

	if (!head_)
		return 0;

	Node* temp = head_; // element to be deleted
	int returnvalue = head_->data;

	if (head_->next) {
		// delete and replace current head
		head_ = head_->next;
		delete temp;
	}
	else {
		head_ = 0;
		delete temp;
	}

	return returnvalue;
}

int LinkedList::pop_back() {

	if (!head_)
		return 0;

	Node* curr = head_;
	int returnValue;

	if (curr->next) { // if list is > 1

		// loop top just before the last element
		while (curr->next->next) {
			curr = curr->next;
		}

		// get value of last element and then delete the node
		returnValue = curr->next->data;
		delete curr->next;
		curr->next = 0;

	}
	else {
		// pop_front since there is only 1 element
		return pop_front();
	}

	return returnValue;
}

void LinkedList::insert_at(int pos, int data) {

	// empty list
	if (!head_) {
		push_back(data);
		return;
	}

	// check negative
	if (pos <= 0) {
		push_front(data);
		return;
	}

	// invalid position
	if (pos > (static_cast<int>(size()) - 1)) {
		push_back(data);
		return;
	}

	Node* newNode = new Node(data);
	Node* curr = head_;
	int index = 0;

	while (curr->next) {

		// traverse until position is reached
		if (index == (pos - 1)) {
			newNode->next = curr->next;
			curr->next = newNode;
			return;
		}

		curr = curr->next;
		++index;

	}

}

int LinkedList::pop_at(int pos) {

	// empty list
	if (!head_)
		return 0;

	// negative check
	if (pos <= 0)
		return pop_front();

	// invalid position
	if (pos > (static_cast<int>(size()) - 1))
		return 0;

	Node* curr = head_;
	Node* temp = 0;
	int index = 0;

	while (curr->next) {

		// loop until position is reached
		if (index == (pos - 1)) {

			temp = curr->next;

			// fill in the gap in between the 2 nodes
			if (curr->next->next) {
				curr->next = curr->next->next;
			}
			else {
				curr->next = nullptr;
			}
			return temp->data;

		}

		curr = curr->next;
		++index;

	}
	return 0;
}

size_t LinkedList::size() {

	if (!head_)
		return 0;

	Node* curr = head_;
	size_t count = 1;

	while (curr->next) {
		curr = curr->next;
		++count;
	}
	return count;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() {
	front_ = 0;
	back_ = 0;
}

Queue::~Queue() {
	// Delete existing nodes
	while (front_) {
		Node* old = front_;
		front_ = front_->next;
		delete old;
	}
}

void Queue::enqueue(int data) {
	Node* newNode = new Node(data);

	if (!front_ && !back_) { // empty list
		front_ = newNode;
		back_ = newNode;
		return;
	}

	back_->next = newNode;
	back_ = newNode;
}

int Queue::dequeue() {

	if (!front_)
		return 0;

	int returnValue = front_->data;

	// Last element in queue
	if (!front_->next) {
		delete front_;
		front_ = 0;
		back_ = 0;
		return returnValue;
	}

	Node* nextNode = front_->next;
	delete front_;
	front_ = nextNode;

	if (front_ == back_) {
		back_ = 0;
	}

	return returnValue;
}

size_t Queue::size() {
	if (!front_)
		return 0;

	Node* curr = front_;
	size_t count = 1;

	while (curr->next) {
		curr = curr->next;
		++count;
	}
	return count;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack() {
	top_ = 0;
}

Stack::~Stack() {
	// Delete existing nodes
	while (top_) {
		Node* old = top_;
		top_ = top_->next;
		delete old;
	}
}

void Stack::push(int data) {
	Node* newNode = new Node(data);

	if (!top_) {
		top_ = newNode;
	}
	else {
		newNode->next = top_; // append backwards since its a stack
		top_ = newNode;
	}
}

int Stack::pop() {
	if (!top_)
		return 0;

	int returnValue = top_->data;
	Node* temp = top_;

	top_ = top_->next;

	delete temp;

	return returnValue;
}

size_t Stack::size() {
	if (!top_)
		return 0;

	Node* curr = top_;
	size_t count = 1;

	while (curr->next) {
		curr = curr->next;
		++count;
	}
	return count;
}



// Balanced parenthesis
bool Brackets(const string& input) {

	const map<char, char> map_Brackets{
		{ '(', ')' },
		{ '{', '}' },
		{ '[', ']' },
		{ '<', '>' },
	};

	std::stack<char> stk_Brackets;
	int pendingBrackets = 0; // number of pending brackets waiting to be closed

	for (char strChar : input) {
		if (map_Brackets.count(strChar)) { // valid open bracket?
			++pendingBrackets;
			stk_Brackets.push(map_Brackets.at(strChar)); // push in closed bracket value
		}
		else {
			if (!stk_Brackets.empty() && stk_Brackets.top() == strChar) {
				pendingBrackets--;
				stk_Brackets.pop();
			}
			else {
				return false;
			}
		}
	}

	// we still have some opened brackets
	if (pendingBrackets) {
		return false;
	}

	return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results) {

	map<int, int> map_Numcounter; // <Number, HitCount>

	for (vector<int>::iterator it = data.begin(); it != data.end(); ++it) {
		map_Numcounter[*it]++; // add Key if doesn't exist and increment value by 1 if exists
	}

	for (vector<int>::iterator it = queries.begin(); it != queries.end(); ++it) {
		results.push_back(map_Numcounter[*it]); // retrieve hitcount from map and store it in the resultant vector
	}

}