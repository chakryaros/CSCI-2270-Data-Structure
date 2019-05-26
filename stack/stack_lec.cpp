#include <iostream>

#define MAX_SIZE 10

using namespace std;

class Stack {
	private:
		int top;
		int maxSize;
		int* data;

	public:
		Stack(int size){
			top = -1;
			maxSize = size;
			data = new int[maxSize];
		}
		~Stack() {
			delete data;
		}

		// Is the stack full?
		bool isFull() {
			return true ? (top == maxSize-1) : false;
		}
		// Is the stack empty?
		bool isEmpty() {
			return true ? (top == -1) : false;
		}

		// Push
		int push(int value){
			if ( isFull() ) {
				return -1;
			}
			top++;
			data[top] = value;
			return 0;
		}
		
		// Pop
		int* pop() {
			if ( isEmpty() ) {
				return NULL;
			}
			//top = top - 1;
			return &data[top--];// using post decrement
		}
};

int main() {
	Stack myStack(MAX_SIZE);
	
	// Test push
	cout << "Push: \n";
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);
	cout << "\tFull?: " << myStack.isFull() << endl;
	cout << "\tEmpty?: " << myStack.isEmpty() << endl;

	// Test pop
	cout << "Pop: \n";
	int* ret = myStack.pop();
	if (ret != NULL) {
		cout << "\tpopped " << *ret << endl;
	} else {
		cout << "\tstack is empty\n";
	}

	ret = myStack.pop();
	if (ret != NULL) {
		cout << "\tpopped " << *ret << endl;
	} else {
		cout << "\tstack is empty\n";
	}

	ret = myStack.pop();
	if (ret != NULL) {
		cout << "\tpopped " << *ret << endl;
	} else {
		cout << "\tstack is empty\n";
	}

	cout << "\tFull?: " << myStack.isFull() << endl;
	cout << "\tEmpty?: " << myStack.isEmpty() << endl;

	return 0;
}