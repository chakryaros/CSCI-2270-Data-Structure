#include <iostream>

using namespace std;

struct node{
	int key;
	node* parent;
	node* leftChild;
	node* rightChild;
};

class BinarySearchTree{
	private:
		node* root;

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

	public:
		BinarySearchTree(int k) {
			root = new node;
			root->key = k;
			root->parent = NULL;
			root->leftChild = NULL;
			root->rightChild = NULL;
		}
		~BinarySearchTree() {
			delete root; // need to delete ALL nodes
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
						return 0;
					}
					tmp = tmp->leftChild;
				} else if (value > tmp->key) {  // go right
					if (tmp->rightChild == NULL) { // insert newNode
						tmp->rightChild = newNode;
						newNode->parent = tmp;
						return 0;
					}
					tmp = tmp->rightChild;
				} else { // duplicate value
					delete newNode;
					return -1;
				}
			}
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
						delete tmp;
						return;
					} else { // There are two children
						node* rightMin = treeMinimum(tmp->rightChild); // find the min from right sub-tree
						
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
};

int main() {
	BinarySearchTree bst(4);

	// Test Insert
	bst.insert(79);
	bst.insert(9);
	bst.insert(5);
	bst.insert(3);
	//bst.insert(1);

	// Test Delete
	//bst.deleteNode(6);

	// Test search
	node* ret = bst.search(5);
	if (ret != NULL) {
		cout << "Found key: " << ret->key << endl;
	} else {
		cout << "Key not found!\n";
	}

	// Test tree Delete
	cout << "Before delete: ";
	bst.inOrderPrint();
	bst.deleteTree();

	// Print for check
	cout << "\nAfter delete: ";
	bst.inOrderPrint();
	return 0;
}