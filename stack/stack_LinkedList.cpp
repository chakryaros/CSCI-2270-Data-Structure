#include <iostream>

using namespace std;


struct node{
    int value;
    struct node* next; // next element
}*top = nullptr;

class Stack {
	private:
		node* top;
		int count;
		int maxSize;
	public:
		Stack(int max) {
			count =0;
			top =NULL;
			maxSize = max;
		}
		bool isFull(){
			if(count==maxSize) {
				return true;
			} else {
				return false;
			}
		}
		bool isEmpty() {
			return true? (top==NULL) : false;
		}
		void push(int data) {
			if(isFull()) {
				cout <<"overflow\n";
			}
			else {
				node* newTop = new node;
				if(top==NULL) {
					newTop->value = data;
					newTop->next = NULL;
					top = newTop;
					count++;
				} 
				else {
					newTop->value = data;
					newTop->next = top;
					top = newTop;
					count++;
				}
			}
		}
		void pop() {
			if(!isEmpty()) {
				node* temp = top;
				top = top->next;
				count--;
				delete temp;
			} else {
				cout <<"nothing to pop";
			}
		}

		void print() {
			node* temp = top;
			while(temp!=NULL) {
				cout<<temp->value<< ", ";
				temp = temp->next;
			}
			cout<<endl;
		}
};

int main() {
	Stack myStack(10);
	for(int i=0; i<10; i++) 
	{
		myStack.push(i+1);
	}
	myStack.print();
	myStack.push(11);
	cout << "\tFull?: " << myStack.isFull() << endl;
	cout << "\tEmpty?: " << myStack.isEmpty() << endl;
	myStack.pop();
	myStack.print();
}