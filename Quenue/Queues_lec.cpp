#include <iostream>

using namespace std;

class Queue {
	private:
		int head, tail;
		int* data;
		int queueSize, maxQueue;
		//Private Methods
		bool isEmpty() {
			return true?(head==tail): false;
		}
		bool isFull() {
			return true?(queueSize==maxQueue): false;
		}
	public:
		Queue(int maxSize) {
			head =0;
			tail = 0;
			queueSize = 0;
			maxQueue = maxSize;
			data = new int[maxQueue];
		}
		~Queue() {
			delete[] data;
		}

		int enqueue(int value) {
			if(isFull()) return -1;
			data[tail++] = value; //post increment
			if(tail==maxQueue){
				tail=0;
			}
			queueSize++;
			return 0;
		}
		int* dequeue() {
			if(isEmpty()) return NULL;
			queueSize--;
			//int temp = &data[head];
			if(head== maxQueue-1)
			{
				head =0;
				return &data[maxQueue-1];
			} else {
				return &data[head++];
			}
			
		}
};

int main() {

	cout.setf(ios_base::boolalpha);
	Queue q(10);
	for(int i=0; i<11; i++) {
		int returned = q.enqueue(i);
		if(returned==-1)
		{
			cout <<"nothing add to Queue"<<endl;
		} else {
			cout <<"enqueue: "<< i <<endl;
		}
	}
	int *ret;
	for(int i=0; i<2; i++)
	{
		ret = q.dequeue();
		if(ret==NULL)
		{
			cout<<"Dequeue returned: NULL\n";
		} else {
			cout<<"Dequeue returned: "<< *ret<<endl;
		}
	}
	
	int returned = q.enqueue(10);
	if(returned==-1)
		{
			cout <<"nothing add to Queue"<<endl;
		} else {
			cout <<"enqueue: "<< "10" <<endl;
		}
	for(int i=0; i<2; i++)
	{
		ret = q.dequeue();
		if(ret==NULL)
		{
			cout<<"Dequeue returned: NULL\n";
		} else {
			cout<<"Dequeue returned: "<< *ret<<endl;
		}
	}

	return 0;
}