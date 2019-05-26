#include <iostream>

using namespace std;

struct doubleNode {
	int key;
	doubleNode* next;
	doubleNode* prev;
};

class doublyLinkedList {
	private:
		doubleNode* head;
		doubleNode* tail;

	public:
		doublyLinkedList(doubleNode* h) {
			head = h;

			doubleNode* tmp = head;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tail = tmp;
		}
		// Forward
		void traverse() {
			doubleNode* tmp = head;
			while(tmp != NULL) {
				cout << tmp->key << ", ";
				tmp = tmp->next;
			}
			cout << endl;
		}
		// Reverse
		void reverseTraverse() {
			doubleNode* tmp = tail;//
			while(tmp != NULL) {
				cout << tmp->key << ", ";
				tmp = tmp->prev;//
			}
			cout << endl;
		}
		// Forward
		doubleNode* search(int searchKey) {
			doubleNode* tmp = head;
			doubleNode* returnNode = NULL;
			bool found = false;

			while ((!found) && (tmp != NULL)){
				if (tmp->key == searchKey) {
					found = true;
					returnNode = tmp;
				} else {
					tmp = tmp->next;
				}
			}
			return returnNode;
		}
		// Reverse
		doubleNode* reverseSearch(int searchKey) {
			doubleNode* tmp = tail; //
			doubleNode* returnNode = NULL;
			bool found = false;

			while ((!found) && (tmp != NULL)){
				if (tmp->key == searchKey) {
					found = true;
					returnNode = tmp;
				} else {
					tmp = tmp->prev; //
				}
			}
			return returnNode;
		}

		
		void insert(int* leftValue, doubleNode* newNode) {
			if (leftValue == NULL) { // insert at head
				newNode->next = head;
				head = newNode;
				head->next->prev = head;
			} else { // insert at middle or tail
				doubleNode* tmp = head;
				while(tmp->key != *leftValue) {
					if (tmp == tail) { // Left value is garbage, BREAK AWAY
						cout << "did not find left value!\n";
						return;
					}
					tmp = tmp->next;
				}
				// newNode update
				newNode->next = tmp->next;
				newNode->prev = tmp;

				tmp->next = newNode;
				if (newNode->next != NULL) { // inserting in the middle
					newNode->next->prev = newNode;
				} else { // inserting at the tail
					tail = newNode;
				}
			}
		}
		void deleteNode(int value) {
			if (head->key == value) { // deleting the head
				doubleNode* tmp = head;
				head = tmp->next;
				tmp->next = NULL;
				head->prev = NULL;
			} else { // deleting from the middle or the tail
				doubleNode* tmp = head;
				while (tmp->next->key != value) {
					tmp = tmp->next;
				}
				doubleNode* deleting = tmp->next;
				
				// move the next pointer from the left of the deleting node to the deleting node's next
				tmp->next = deleting->next; 				
				deleting->next = NULL;
				deleting->prev = NULL;
				if (tmp->next != NULL) { // In the middle
					tmp->next->prev = tmp;
				} else { // At the end
					tail = tmp;
				}
			}
		}
};

int main() {
	doubleNode head;
	head.key = 5;
	head.prev = NULL;

	// Do it by hand
	doubleNode b;
	b.key = 6;
	b.prev = &head;
	head.next = &b;
	//head.next = &b;

	doubleNode c;
	c.key = 7;
	c.next = NULL;
	b.next = &c;
	c.prev = &b;
	//head.next = &c;

	// Initialize object
	doublyLinkedList list(&head);
	cout << "initial: \n";
	list.traverse();
	list.reverseTraverse();

	// Delete
	cout << "after delete: \n";
	list.deleteNode(5);
	list.traverse();
	list.reverseTraverse();

	// Search
	cout << "search: ";
	doubleNode* returnNode = list.reverseSearch(7);
	if (returnNode != NULL) {
		cout << returnNode->key << endl;
	} else {
		cout << "returned NULL\n";
	}

	// Insert
	cout << "insert: \n";
	doubleNode d;
	d.key = 8;
	d.prev = NULL;
	d.next = NULL;
	int leftVal = 5;
	list.insert(&leftVal, &d);
	list.traverse();
	list.reverseTraverse();
	
	return 0;
}