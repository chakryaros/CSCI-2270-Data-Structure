#include <iostream>

using namespace std;

class Queue {
	private:
		int head, tail;
		int* data;
		int queueSize, maxQueue;
		// Private Methods
		bool isEmpty() {
			return true ? (queueSize == 0) : false;
		}
		bool isFull() {
			return true ? (queueSize == maxQueue) : false;
		}
	
	public:
		Queue(int maxSize) {
			head = 0;
			tail = 0;
			queueSize = 0;
			maxQueue = maxSize;
			data = new int[maxQueue];
		}
		~Queue() {
			delete[] data;
		}

		int enqueue(int value) {
			if ( isFull() ) return -1;
			data[tail++] = value;
			if (tail == maxQueue) {
				tail = 0;
			}
			queueSize++;
			return 0;
		}

		int* dequeue() {
			if ( isEmpty() ) return NULL;
			queueSize--;
			if (head == maxQueue-1) {
				head = 0;
				return &data[maxQueue-1];
			} else {
				return &data[head++];
			}
		}
};

int main() {
	cout.setf(ios_base::boolalpha); // make true/false print pretty

	Queue q(10);
	
	// Test enqueue & dequeue
	cout << "Enqueue: \n";
	for (int i=0; i<11; i++) {
		int returned = q.enqueue(i);
		if (returned == -1) {
			cout << "\tQueue is FULL\n";
		} else {
			cout << "\tEnqueued " << i << endl;
		}
	}

	cout << "Dequeue: \n";
	int* ret;
	for (int i=0; i<2; i++) {
		ret = q.dequeue();
		if (ret == NULL) {
			cout << "\tDequeue returned: NULL\n";
		} else {
			cout << "\tDequeue returned: " << *ret << endl;
		}
	}
	
	int returned = q.enqueue(10);
	if (returned == -1) {
		cout << "\tQueue is FULL\n";
	} else {
		cout << "\tEnqueued " << "10" << endl;
	}
	for (int i=0; i<10; i++) {
		ret = q.dequeue();
		if (ret == NULL) {
			cout << "\tDequeue returned: NULL\n";
		} else {
			cout << "\tDequeue returned: " << *ret << endl;
		}
	}

	return 0;
}