#include<iostream>

using namespace std;

struct doubleNode{
	int key;
	doubleNode* next;
	doubleNode* prev;
};

class doubleLinkedList {
	private:
		doubleNode* head;
		doubleNode* tail;
	public:
		doubleLinkedList(doubleNode* h)
		{
			head = h;
			doubleNode* temp = head;
			while(temp!=NULL){
				temp = temp->next;
			}
			tail = temp;
		}
		void traverse() {
			doubleNode* temp = head;
			while(temp!=NULL){
				cout <<temp->key <<", ";
				temp = temp->next;
			}
			cout<<endl;
		}
		void ReverseTraverse() {
			doubleNode* temp = tail;
			while(temp!=NULL){
				cout<<temp->key<<", ";
				temp = temp->prev;
			}
			cout<<endl;	
		}
		doubleNode* searchNode(int value) {
			doubleNode* temp = head;
			doubleNode* returnNode = NULL;
			bool found = false;
			while((!found)&&(temp!=NULL)) {
				if(temp->key==value) {
					found = true;
					returnNode = temp;
				} else {
					temp = temp->next;
				}
			}
			return returnNode;
		}
		doubleNode* reverseSearch(int value) {
			doubleNode* temp = tail;
			doubleNode* returnNode = NULL;
			bool found = false;
			while((!found) && temp!=NULL) {
				if(temp->key==value) {
					found = true;
					returnNode=temp;
				} else {
					temp = temp->prev;
				}
			}
			return returnNode;
		}

		void insertNode(int* leftValue, doubleNode* newNode)
		 {
			if(leftValue==NULL)
			 {
				newNode->next = head;
				head = newNode;
				head->next->prev = head;
			} 
			else 
			{
				doubleNode* temp = head;
				while(temp->key!=*leftValue) 
				{
					if(tail==NULL) 
					{
						cout<<"did not find the leftvalue"<<endl;
						return;
					}
					temp = temp->next;
				}
				newNode->next = temp->next;
				newNode->prev = temp;
				temp->next = newNode;
				if(newNode->next!=NULL) 
				{
					newNode->next->prev = newNode;
				} 
				else 
				{
					tail = newNode;
				}
			}
			
		}
		void deleteNode(int value) {
			if(head->key==value) {
				doubleNode* temp = head;
				head = temp->next;
				temp->next=NULL;
				temp->prev = NULL;
			} else {
				doubleNode* temp = head;
				while(temp->next->key!=value) {
					temp = temp->next;
				}
				doubleNode* deleting = temp->next;
				temp->next = deleting->next;
				deleting->next = NULL;
				deleting->prev =NULL;
				if(temp->next!=NULL) {
				temp->next->prev = temp;
				} else {
					tail = temp;
				}
			}
		}
};

int main() 
{

	doubleNode head;
	head.key = 5;
	head.prev = NULL;

	doubleNode b;
	b.key = 6;
	b.prev = &head;
	head.next = &b;

	doubleNode c;
	c.key = 7;
	c.prev = &b;
	c.next =NULL;
	b.next = &c;

	doubleLinkedList list(&head);
	cout <<"inital: \n";
	list.traverse();
	list.ReverseTraverse();

	cout <<"After delete:\n";
	list.deleteNode(6);
	list.traverse();
	list.ReverseTraverse();

	cout<<"search: ";
	doubleNode* returnNode = list.reverseSearch(7);
	if(returnNode !=NULL) {
		cout<< returnNode->key <<endl;
	} else {
		cout<<"returned NULL\n";
	}

	cout <<"insert:\n";
	doubleNode* d;
	d->key = 8;
	d->prev= NULL;
	d->next =NULL;
	int leftvalue =5;
	list.insertNode(&leftvalue, d);
	list.traverse();

	return 0;
}


