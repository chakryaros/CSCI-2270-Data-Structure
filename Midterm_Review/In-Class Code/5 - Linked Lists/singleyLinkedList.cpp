#include <iostream>

using namespace std;

struct singleNode{
	int key;
	singleNode* next;
};

class singlyLinkedList{
	private:
		singleNode* head;

	public:
		singlyLinkedList(singleNode* h){
			head = h;
		}

		// Printing the contents of a linked list
		void traverse(){
			singleNode* tmp = head;
			while(tmp != NULL){
				if(tmp->next == NULL){
					cout << tmp->key << endl;
				}
				else{
				cout << tmp->key << ", ";
				}
				tmp = tmp->next;
			}
		}

		// Searching through a linked list for a number
		singleNode* search(int searchKey){
			singleNode* tmp = head;
			singleNode* returnNode = NULL;
			bool found = false;

			while(found == false && (tmp != NULL)){
				if(tmp->key == searchKey){
					found = true;
					returnNode = tmp;
				}
				else{
					tmp = tmp->next;
				}
			}
			return returnNode;
		}

		// Inserting at the head of a linked list
		void insertHead(singleNode* newNode){
			newNode->next = head;
			head = newNode;
		}

		// Inserting at the tail of a linked list
		void insertTail(singleNode* newNode){
			singleNode* tmp = head;
			while(tmp->next != NULL){
				tmp = tmp->next;
			}
			tmp->next = newNode;
		}

		// A full insert function - can insert at head, middle, or tail
		void insert(int* leftValue, singleNode* newNode){
			if (leftValue == NULL){
				newNode->next = head;
				head = newNode;
			}
			else{
				singleNode* tmp = head;
				while(tmp->key != *leftValue){
					tmp = tmp->next;
				}
				newNode->next = tmp->next;
				tmp->next = newNode;
			}
		}

		// Deletes a node from the Linked List
		void deleteNode(int value){
			singleNode* tmp = head;

			if (head->key == value){ //If head-> key is the value, delete the head
				head = tmp->next;
				tmp->next = NULL;
			}
			else{ // Delete at the middle of the tail
				while(tmp->next->key != value){
					tmp = tmp->next;
				}
				singleNode* deleting = tmp-> next;
				tmp->next = deleting->next; // Move the next pointer from the left of the deleting node to the deleting node's next
				deleting->next = NULL;
			}
		}
};

int main() {
	singleNode head;
	head.key = 5;
	head.next = NULL; // The very last thing in every linked list is always NULL

	// Implement Linked List by Hand
	cout << "--Implement Linked List by Hand--\n" << endl;

		singleNode b;
		b.key = 6;
		b.next = NULL;
		head.next = &b; // Create a pointer from head.next to b

		singleNode c;
		c.key = 7;
		c.next = NULL;
		head.next->next = &c; // We want to reference all pointers to the head

		cout << "head.key: " << head.key << endl;
		cout << "head.next: " << head.next << endl; // Should print the address of b
		cout << "b.key: " << b.key << endl;
		cout << "head.next->key: " << head.next->key << endl; // head.next is interchangeable with b.key
		cout << "head.next->next->key: " << head.next->next->key << endl; // Dereference head.next, look at the next list, deference that list, and then look at the last key

		cout << endl << endl;


	// Implement Linked List by Class
	cout << "--Implement Linked List by Class--\n" << endl;

		singlyLinkedList list(&head);
	
		cout << "traverse list: ";
		list.traverse();

		singleNode* searchReturn = list.search(8);
		if(searchReturn != NULL){
				cout << "search returned (8): " << searchReturn->key << endl;
		}
		else{
			cout << "search returned (8): NULL" << endl;
		}

		searchReturn = list.search(6);
		if(searchReturn != NULL){
				cout << "search returned (6): " << searchReturn->key << endl;
		}
		else{
			cout << "search returned (6): NULL" << endl;
		}

		// Insert at the head
		singleNode d;
		d.key = 4;
		d.next = NULL;
		list.insertHead(&d);
		cout << "insertHead: ";
		list.traverse();

		// Insert at the tail
		singleNode e;
		e.key = 9;
		e.next = NULL;
		list.insertTail(&e);
		cout << "insertTail: ";
		list.traverse();

		cout << endl << endl;

	// Inserting with one insert function
	cout << "--Inserting with One Insert Function--\n" << endl;
	
		int leftValue = 7;

		// Insert after the 7
		singleNode f;
		f.key = 8;
		f.next = NULL;
		list.insert(&leftValue, &f);
		cout << "insert after 7: ";
		list.traverse();

		// Insert at head
		singleNode g;
		g.key = 3;
		g.next = NULL;
		list.insert(NULL, &g);
		cout << "insert at the head: ";
		list.traverse();

	cout << endl << endl;

	//Deleting a list from the linked list
	cout << "--Deleting from a Linked List--\n" << endl;

		list.deleteNode(3);
		cout << "delete head: ";
		list.traverse();

		list.deleteNode(6);
		cout << "delete 6: ";
		list.traverse();

		list.deleteNode(9);
		cout << "delete tail: ";
		list.traverse();

		cout << endl;

		list.deleteNode(5);
		list.deleteNode(4);
		list.deleteNode(8);
		list.deleteNode(7);
		cout << "delete all: ";
		list.traverse();
		cout << endl;

		cout << "head.next: ";
		cout << head.next << endl;

	cout << endl << endl;

	return 0;
}