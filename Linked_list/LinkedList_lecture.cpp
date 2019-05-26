#include <iostream>

using namespace std;

struct singleNode {
	int key;
	singleNode* next;
};

class singlyLinkedList {
	private:
		singleNode* head;

	public:
		singlyLinkedList(singleNode* h) {
			head = h;
		}

		void traverse() {
			singleNode* tmp = head;
			while(tmp != NULL) {
				cout << tmp->key << ", ";
				tmp = tmp->next;
			}
			cout << endl;
		}

		singleNode* search(int searchKey) {
			singleNode* tmp = head;
			singleNode* returnNode = NULL;
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

		void insertHead(singleNode* newNode) {
			newNode->next = head;
			head = newNode;
		}
/* Not needed anymore - depracated 
		void insertTail(singleNode* newNode) {
			singleNode* tmp = head;
			while(tmp->next != NULL) {
				tmp = tmp->next;
			}
			tmp->next = newNode;
		}
*/
		void insert(int* leftValue, singleNode* newNode) {
			if (leftValue == NULL) { // insert at head
				newNode->next = head;
				head = newNode;
			} else { // insert at middle or tai
				singleNode* tmp = head;
				while(tmp->key != *leftValue) {
					tmp = tmp->next;
				}
				newNode->next = tmp->next;
				tmp->next = newNode;
			}
		}

		void deleteNode(int value) {
			if (head->key == value) { // deleting the head
				singleNode* tmp = head;
				head = tmp->next;
				tmp->next = NULL;
			} else { // deleting from the middle or the tail
				singleNode* tmp = head;
				while (tmp->next->key != value) {
					tmp = tmp->next;
				}
				singleNode* deleting = tmp->next;
				tmp->next = tmp->next->next; // move the next pointer from the left of the deleting node to the deleting node's next
				deleting->next = NULL;
			}
		}
};

int main() {
	singleNode head;
	head.key = 5;
	head.next = NULL;

	// Do it by hand
	singleNode b;
	b.key = 6;
	b.next = NULL;
	//head.next = &b;

	singleNode c;
	c.key = 7;
	c.next = NULL;
	head.next = &c;

	cout << "key: " << head.key << endl;
	cout << "next: " << head.next << endl;
	cout << "next key: " << head.next->key << endl;
	//cout << "last key: " << head.next->next->key << endl;

	// Implement Class
	singlyLinkedList list(&head);
	list.traverse();

	singleNode* searchReturn = list.search(8);
	if (searchReturn != NULL) {
		cout << "search returned: " << searchReturn->key << endl;
	} else {
		cout << "search returned: NULL\n";
	}

	// Test insert
	singleNode d;
	d.key = 4;
	list.insertHead(&d);
	list.traverse();
	int* leftValue;//leftValue$ = malloc(sizeof(int));
	int val = 5;
	leftValue = &val;
	list.insert(leftValue, &b);
	list.traverse();

	singleNode e;
	e.key = 12;
	leftValue = NULL;
	list.insert(leftValue, &e);
	list.traverse();

	// Test delete
	list.deleteNode(12);
	list.traverse();
	list.deleteNode(7);
	list.traverse();
	list.deleteNode(5);
	list.traverse();
	list.deleteNode(4);
	list.traverse();
	list.deleteNode(6);
	list.traverse();

	cout << head.next << endl;;

	return 0;
}