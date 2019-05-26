#include <iostream>

#define MAX_SIZE 10 // Gives you a "private" global variable. Makes it so that it cannot be abused / modified 

using namespace std;

class Stack{ // Using an array for our stack
	private:
		int top; // Maintaining an index to the array
		int maxSize = 10; // The maximum size of the array
		int* data; // The array as a pointer

	public:
		Stack(int size){ // Our constructor to allocate memory
			top = -1; // Top is -1 because if something is in the stack, the minimum value of top is 0.
			maxSize = size;
			data = new int[maxSize];
		}
		~Stack(){ // Our deconstructor
			delete data;
		}

		// Is the stack full?
		bool isFull(){
			return true ? (top == maxSize - 1) : false; // A quick way to write a conditional statement if there isn't a lot in the statement
		}

		// Is the stack empty?
		bool isEmpty(){
			return true ? (top == -1) : false;
		}

		// Push
		int push(int value){
			if(isFull()){
				return -1;
			}

			top++; // Increment top before we pass the value (move it from -1)
			data[top] = value;

			return 0; // Return 0 if everything goes well
		}

		// Pop
		int* pop(){
			if(isEmpty()){
				return NULL; // Need to return NULL because this is a pointer to the stack
			}



			return &data[top--];
		}
};

int main(){
	Stack myStack(MAX_SIZE);

	// Test Full/Empty
	cout << "--TEST FULL/EMPTY--" << endl;
	cout << "\tFull?: " << myStack.isFull() << endl;
	cout << "\tEmpty?: " << myStack.isEmpty() << endl;
	cout << endl;

	// Test push
	int returned;
	cout << "--PUSH--" << endl;
	for(int i = 0; i < 11; i++){	
		returned = myStack.push(i+1); //Push values 1-11 into the 10 slot array
		if(!returned){ //If the value is pushed print "Pushed: num"
			cout << "\tPushed: " << i+1 << endl;
		}
		else{ // If the stack is full, give error message
			cout << "\tStack is full! Failed to push " << i << "." << endl;
		}
	}
	cout << "\tFull after push?: " << myStack.isFull() << endl;
	cout << "\tEmpty after push?: " << myStack.isEmpty() << endl;
	cout << endl;

	// Test pop
	cout << "--POP--" << endl;
	int* ret; // Pop 3
	for(int i = 0; i < 11; i++){
		ret = myStack.pop();
		if(ret != NULL){ // If the value is popped tell which value was popped.
			cout << "\tPopped: " << *ret << endl;
		}
		else{ // If there is no value to pop, give error message
			cout << "\tStack is empty." << endl;
		}
	}

	cout << "\tFull after pop?: " << myStack.isFull() << endl;
	cout << "\tEmpty after pop?: " << myStack.isEmpty() << endl;

	return 0;
}