#include <iostream>
#include <cmath>
#include <algorithm> // for max()

using namespace std;

struct node{
	int key;
	node* parent;
	node* leftChild;
	node* rightChild;
};

class AVLTree{
	private:
		node* root;
		int height;

		node* searchRecursive(node* n, int value){
			if (n == NULL) { 
				return NULL;
			}
			if (value == n->key) {
				return n;
			} else if (value < n->key) { // going left
				return searchRecursive(n->leftChild, value);
			} else if (value > n->key) { // going right
				return searchRecursive(n->rightChild, value);
			}
		}

		void printNode(node* n) { // in-order traversal
			if (n == NULL) {
				return;
			}
			if (n->leftChild != NULL) {
				printNode(n->leftChild);
			}
			cout << n->key << " ";
			if (n->rightChild != NULL) {
				printNode(n->rightChild);
			}
		}

		node* treeMinimum(node* n) {
			while (n->leftChild != NULL) { // there is a smaller value
				n = n->leftChild;
			}
			return n;
		}

		void deleteTreePrivate(node* n) {
			if (n == NULL) {
				return;
			}
			if (n->leftChild != NULL) { // delete all left children
				deleteTreePrivate(n->leftChild);
			}
			if (n->rightChild != NULL) { // delete all right children
				deleteTreePrivate(n->rightChild);
			}
			if (root == n) {
				root = NULL;
			};
			delete n;
		}

		int findHeight(node* n) {
			if (n == NULL) { // Height of empty tree is -1
				return -1;
			}
			int h = 1 + max(findHeight(n->leftChild), findHeight(n->rightChild));
			return h;
		}

		node* findViolations(node* n) {
			if (n == NULL) {
				cout << "Found no violations\n";
				return NULL;
			}
			int hDiff = abs(findHeight(n->leftChild) - findHeight(n->rightChild));
			if ( hDiff > 1 ) { // AVL break condition;
				return n;
			}
			return findViolations(n->parent);
		}

		void leftRotate(node* k2, node* k1) {
			if (k2->parent != NULL) { // figure out where k2 is relative to the parent
				if (k2->key < k2->parent->key) { // k2 is left of its parent
					k2->parent->leftChild = k1;
				} else { // k2 is right of its parent
					k2->parent->rightChild = k1;
				}
			} else {
				root = k1;
			}
			k1->parent = k2->parent;

			k2->rightChild = k1->leftChild; // pass the Y triangle to k2
			if (k2->rightChild != NULL) {
				k2->rightChild->parent = k2;
			}

			k1->leftChild = k2;
			k2->parent = k1;
		}

		void rightRotate(node* k2, node* k1) {
			if (k2->parent != NULL) { // figure out where k2 is relative to the parent
				if (k2->key < k2->parent->key) { // k2 is left of its parent
					k2->parent->leftChild = k1;
				} else { // k2 is right of its parent
					k2->parent->rightChild = k1;
				}
			} else {
				root = k1;
			}
			k1->parent = k2->parent;

			k2->leftChild = k1->rightChild; // pass the Y triangle to k2
			if (k2->leftChild != NULL) {
				k2->leftChild->parent = k2;
			}

			k1->rightChild = k2;
			k2->parent = k1;
		}


	public:
		AVLTree(int k) {
			root = new node;
			root->key = k;
			root->parent = NULL;
			root->leftChild = NULL;
			root->rightChild = NULL;

			height = 0;
		}
		~AVLTree() {
			deleteTree(); // need to delete ALL nodes
		}

		int insert(int value) {
			// Initialize new node
			node* newNode = new node;
			newNode->key = value;
			newNode->parent = NULL;
			newNode->leftChild = NULL;
			newNode->rightChild = NULL;

			// Find out where it goes
			node* tmp = root;
			while (1) {
				if (value < tmp->key) { // go left

					if (tmp->leftChild == NULL) { // insert newNode
						tmp->leftChild = newNode;
						newNode->parent = tmp;
						break;
					}
					tmp = tmp->leftChild;

				} else if (value > tmp->key) {  // go right

					if (tmp->rightChild == NULL) { // insert newNode
						tmp->rightChild = newNode;
						newNode->parent = tmp;
						break;
					}
					tmp = tmp->rightChild;

				} else { // duplicate value
					delete newNode;
					return -1;
				}
			}

			// check if we broke things, AVL condition
			node* violator = findViolations(newNode->parent);
			if (violator != NULL) { // we broke it
				if (newNode->key < violator->key) { // k1 is left of violator
					if (newNode->key < violator->leftChild->key) { // we are left
						// left outer violation
						cout << "left outer\n";
						rightRotate(violator, violator->leftChild);
					} else { // k1 is right of violator
						// left inner violation
						cout << "left inner\n";
						leftRotate(violator->leftChild, violator->leftChild->rightChild);
						rightRotate(violator, violator->leftChild);
					}
				} else  { // we are right
					if (newNode->key < violator->rightChild->key) { // k1 is left of violator
						// right inner violation
						cout << "right inner\n";
						rightRotate(violator->rightChild, violator->rightChild->leftChild);
						leftRotate(violator, violator->rightChild);
					} else { // k1 is right of violator
						// right outer
						cout << "right outer\n";
						leftRotate(violator, violator->rightChild);
					}
				}
			}
			return 0;
		}

		void inOrderPrint() {
			printNode(root);
		}
		node* search(int value) {
			return searchRecursive(root, value);
		}

		void deleteNode(int value) { // head node needs support
			node* tmp = root;
			while (tmp != NULL) {
				if (tmp->key == value) { // found the node!
					// != is our XOR operator
					if ((tmp->leftChild != NULL) != (tmp->rightChild != NULL)) { // One of these is not null
						if (tmp->leftChild != NULL) { // filling the hole with the left

							if (value < tmp->parent->key) { // left of the parent
								tmp->parent->leftChild = tmp->leftChild;
							} else {  // right of the parent
								tmp->parent->rightChild = tmp->leftChild;
							}
							tmp->leftChild->parent = tmp->parent;

						} else { // filling the hole with the right

							if (value < tmp->parent->key) { // left of the parent
								tmp->parent->leftChild = tmp->rightChild;
							} else {  // right of the parent
								tmp->parent->rightChild = tmp->rightChild;
							}
							tmp->rightChild->parent = tmp->parent;

						}
						delete tmp;
						return;

					} else if (tmp->leftChild == tmp->rightChild) { // No children!
						if (value < tmp->parent->key) {
							tmp->parent->leftChild = NULL;
						} else {
							tmp->parent->rightChild = NULL;
						}
						// 4, 2, 6,5,1,7,8 delete 2, so violate is 4

						// Find violations
						node* violator = findViolations(tmp->parent);
						if (violator != NULL) { // we broke it
							if (tmp->key < violator->key) { // we have a right violation
								node* k1 = violator->rightChild;
								if (findHeight(k1->leftChild) < findHeight(k1->rightChild)) {
									// right outer
									cout << "right outer\n";
									leftRotate(violator, violator->rightChild);
								} else {
									// right inner violation
									cout << "right inner\n";
									rightRotate(violator->rightChild, violator->rightChild->leftChild);
									leftRotate(violator, violator->rightChild);
								}
							} else  { // we have a left violation
								node* k1 = violator->leftChild;
								if (findHeight(k1->leftChild) < findHeight(k1->rightChild)) { // k1 is left of violator
									// left inner violation
									cout << "left inner\n";
									leftRotate(violator->leftChild, violator->leftChild->rightChild);
									rightRotate(violator, violator->leftChild);
								} else { // k1 is right of violator
									// left outer violation
									cout << "left outer\n";
									rightRotate(violator, violator->leftChild);
								}
							}
						}
						//delete tmp;
						return;

					} else { // There are two children
						node* rightMin = new node;
						rightMin = treeMinimum(tmp->rightChild); // find the min from right sub-tree
						deleteNode(rightMin->key);
						// Update parent pointers
						if (value < tmp->parent->key) {
							tmp->parent->leftChild = rightMin;
						} else {
							tmp->parent->rightChild = rightMin;
						}
						rightMin->parent = tmp->parent;

						// Update left child
						rightMin->leftChild = tmp->leftChild;
						tmp->leftChild->parent = rightMin;

						// Update right child
						if (rightMin->key != tmp->rightChild->key) { // Checks if they are not the same
							rightMin->rightChild = tmp->rightChild;
							tmp->rightChild->parent = rightMin;
						} // are we done?
						//if (rightMin->key != rightMin->parent->key) // Continue from here
							//return;


						//find violation
						node* violator = tmp;
						while(violator != NULL)
						{
							violator = findViolations(violator->parent);
							if(violator != NULL) 
							{
								if (tmp->key < violator->key) { // we have a right violation
								node* k1 = violator->rightChild;
								if (findHeight(k1->leftChild) < findHeight(k1->rightChild)) {
									// right outer
										cout << "right outer\n";
										leftRotate(violator, violator->rightChild);
								} else {
									// right inner violation
										cout << "right inner\n";
										rightRotate(violator->rightChild, violator->rightChild->leftChild);
										leftRotate(violator, violator->rightChild);
									}
								} 
								else  { // we have a left violation
									node* k1 = violator->leftChild;
									if (findHeight(k1->leftChild) < findHeight(k1->rightChild)) { // k1 is left of violator
									// left inner violation
									cout << "left inner\n";
									leftRotate(violator->leftChild, violator->leftChild->rightChild);
									rightRotate(violator, violator->leftChild);
									} else { // k1 is right of violator
									// left outer violation
									cout << "left outer\n";
									rightRotate(violator, violator->leftChild);
									}
								}
							}
						}
						delete tmp;
						return;
					}
				} else {
					if (value < tmp->key) { // move left
						tmp = tmp->leftChild;
					} else { // move right
						tmp = tmp->rightChild;
					}
				}
			}
		}

		void deleteTree() {
			deleteTreePrivate(root);
		}

		void printRoot() {
			cout << "Root is: " << root->key << endl;
		}

		void treeHeight() {
			cout << "Tree height is: " << findHeight(root) << endl;
		}
};

int main() {
	AVLTree bst(6);

	// Test Insert
	cout << "Inserting: " << 3 << " - ";
	bst.insert(3);
	cout << endl;

	cout << "Inserting: " << 8 << " - ";
	bst.insert(8);
	cout << endl;

	cout << "Inserting: " << 2 << " - ";
	bst.insert(2);
	cout << endl;

	cout << "Inserting: " << 4 << " - ";
	bst.insert(4);
	cout << endl;


	cout << "Inserting: " << 7 << " - ";
	bst.insert(7);
	cout << endl;

	cout << "Inserting: " << 1 << " - ";
	bst.insert(1);
	cout << endl;

	cout << "Inserting: " << 9<< " - ";
	bst.insert(9);
	cout << endl;

	

	// Print for check
	cout << "\nAfter inserts: ";
	bst.inOrderPrint();
	cout << endl;

	// Test Delete
	cout << "Deleting: " << 8 << " - ";
	bst.deleteNode(8);
	cout << endl;

	// Print for check
	cout << "\nAfter inserts: ";
	bst.inOrderPrint();
	cout << endl;

	bst.printRoot();
	bst.treeHeight();
	return 0;
}