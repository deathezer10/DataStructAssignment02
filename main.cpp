#include "DetectMemoryLeak.h"
#include <string>
#include <vector>
#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::string;
using std::vector;


bool Brackets(const string& input);
void QueryMachine(vector<int>& data, vector<int>& queries, vector<unsigned int>& results);

double timeTaken(clock_t startTime);

// this ensures that _CrtDumpMemoryLeaks() is called after main() and right before program terminates
struct AtExit {
	~AtExit() { _CrtDumpMemoryLeaks(); }
} doAtExit;

int main() {
	// This sets the boolean values to be represented in a textual format.
	cout << std::boolalpha;

	// Start the clock
	clock_t start = clock();

	// part 1
	cout << "Part 1" << endl;
	LinkedList ll;
	ll.push_front(333);
	ll.push_back(111);
	cout << ll.size() << endl;
	cout << ll.pop_back() << endl;
	cout << ll.pop_front() << endl;
	cout << ll.pop_back() << endl;
	ll.insert_at(5, 10);
	cout << ll.pop_at(1) << endl;
	/*
	for (int i = 0; i < 40000; ++i) {
	ll.push_back(i); // Traversing the list is so slow :(
	}
	*/
	cout << endl;

	cout << "Time taken to run the above code is " << timeTaken(start) << "ms" << endl << endl;

	// part 2
	cout << "Part 2" << endl;
	Queue q;
	q.enqueue(1);
	cout << q.dequeue() << endl;
	q.enqueue(2);
	cout << q.dequeue() << endl;
	q.enqueue(3);
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	q.enqueue(4);
	cout << q.dequeue() << endl;
	cout << q.size() << endl;
	cout << endl;

	// part 3
	cout << "Part 3" << endl;
	Stack s;
	s.push(46);
	s.push(8);
	cout << s.pop() << endl;
	cout << s.size() << endl;
	cout << endl;

	// part 4
	cout << "Part 4" << endl;
	std::string tests[11] = {
		"()[]<>{}",
		"(<",
		"]}",
		"()<",
		"(][)",
		"((]([)]",
		"()()[]<>{{[{}]}}",
		"{<[()]>}",
		"(<))",
		"(<))",
		"()"
	};
	for (std::string s : tests) {
		cout << Brackets(s) << endl;
	}
	cout << endl;


	// part 5
	cout << "Part 5" << endl;
	int dataArray[] = { 1, 2, 3, 4, 3, 2, 2, 6 };
	int queryArray[] = { 1, 2, 3 };

	vector<int> data(dataArray, dataArray + sizeof(dataArray) / sizeof(dataArray[0]));
	vector<int> queries(queryArray, queryArray + sizeof(queryArray) / sizeof(queryArray[0]));
	vector<unsigned int> results;
	QueryMachine(data, queries, results);
	for (size_t i = 0; i < results.size(); ++i) {
		cout << results[i] << " ";
	}
	cout << endl;


	return 0;
}

// If you are curious, this calculates the time taken between the start time and the time that this function is called.
// The return value is in milliseconds (ms)
double timeTaken(clock_t startTime) {
	return (clock() - startTime) / (double)(CLOCKS_PER_SEC / 1000);
}

