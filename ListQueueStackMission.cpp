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
	// todo delete?
}

void LinkedList::push_front(int data) {

	Node* newNode = new Node(data);

	if (!head_) {
		head_ = newNode;
	}
	else {
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

		while (curr->next->next) {
			curr = curr->next;
		}

		returnValue = curr->next->data;
		delete curr->next;
		curr->next = 0;

	}
	else {
		return pop_front();
	}

	return returnValue;
}

void LinkedList::insert_at(int pos, int data) {

	if (!head_) {
		push_back(data);
		return;
	}

	if (pos <= 0) {
		push_front(data);
		return;
	}

	if (pos > (size() - 1)) {
		push_back(data);
		return;
	}

	Node* newNode = new Node(data);
	Node* curr = head_;
	size_t index = 0;

	while (curr->next) {

		if (index == (pos - 1)) {
			newNode->next = curr->next;
			curr->next = newNode;
			return;
		}

		curr = curr->next;
		index++;

	}

}

int LinkedList::pop_at(int pos) {

	if (!head_) {
		return 0;
	}

	if (pos <= 0) {
		return pop_front();		
	}

	if (pos > (size() - 1)) {
		return 0;
	}

	Node* curr = head_;
	Node* temp = 0;
	size_t index = 0;

	// First element
	if (index == pos) {
		temp = curr;
		head_ = curr->next;
		return temp->data;
	}

	while (curr->next) {

		if (index == (pos - 1)) {

			temp = curr->next;

			if (curr->next->next) {
				curr->next = curr->next->next;
			}
			else {
				curr->next = nullptr;
			}
			return temp->data;

		}

		curr = curr->next;
		index++;

	}

}

size_t LinkedList::size() {

	if (!head_)
		return 0;

	Node* curr = head_;
	size_t count = 1;

	while (curr->next) {
		curr = curr->next;
		count++;
	}
	return count;
}

//*******************************************************************//
// Queue stuff
//*******************************************************************//
Queue::Queue() {
}

Queue::~Queue() {
}

void Queue::enqueue(int data) {
}

int Queue::dequeue() {
	return 0;
}

size_t Queue::size() {
	return 0;
}

//*******************************************************************//
// Stack stuff
//*******************************************************************//
Stack::Stack() {

}

Stack::~Stack() {
}

void Stack::push(int data) {
}

int Stack::pop() {
	return 0;
}

size_t Stack::size() {
	return 0;
}



// Balanced parenthesis
bool Brackets(const string& input) {
	return true;
}

// Query machine, hits
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results) {
}