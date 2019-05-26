#include <iostream>

using namespace std;

struct node {
	int key;
	node* next;
};

void ReverseLinkedList(node** head) {
	node* current = *head;
	node* prev = NULL;
	node* next;
	while(current!=NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void push(node **head, int data) {
	node* newNode = new node;
	newNode->key = data;
	newNode->next = *head;
	*head = newNode;
}
void printList(node* head) {
	node* temp = head;
	while(temp!=NULL) {
		cout<<temp->key << " ";
		temp =temp->next;
	}
	cout <<endl;
}

int main() {
	node* head = NULL;
	push(&head, 0);
	push(&head, 0);
	push(&head, 50);
	push(&head, 100);
	cout<<" original lisked list" <<endl;
	printList(head);
	ReverseLinkedList(&head);
	cout<<"Reversed lisked list"<<endl;
	printList(head);
}