#include <iostream>

using namespace std;

struct Node {
	int val;
	Node *next;
};

int LinkedListFindMin(Node *head) {
	Node* current = head;
	int min = current->val;
    while (current != NULL) {
    	if (current->val < min) {
    		min = current->val;
    	}
    	current = current->next;
    }
	return min;
}

int mian()
{
	LinkedListFindMin(5);
	//cout<<output<<endl;
}