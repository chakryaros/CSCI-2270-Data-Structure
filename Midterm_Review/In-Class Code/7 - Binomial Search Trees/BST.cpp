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
		node* root; // Only node without a parent pointer
		int* searchRecursive(node*, int value){
			return NULL;
		}

		void printNode(node* n){
			if(n->leftChild != NULL){
				printNode(n->leftChild);
			}

			cout << n->key << " ";

			if(n->rightChild != NULL){
				printNode(n->rightChild);
			}
		}

	public:
		BinarySearchTree(int value){
			root = new node;
			root->key = value;
			root->parent = NULL; // Root's parent is always set to NULL
			root->leftChild = NULL; // We haven't determined it's children yet
			root->rightChild = NULL;
		}
		~BinarySearchTree(){
			delete root; //Need to delete ALL nodes - This only deletes the root
		}

		int insert(int value){
			//Initialize new node
			node* newNode = new node;
			newNode->key = value;
			newNode->parent = NULL; // In this function, the tmp is out parent
			newNode->leftChild = NULL;
			newNode->rightChild = NULL;

			// Figure out where new node goes
			node* tmp = root;
			while(tmp != NULL){ // Run it off until the end of the tree
				if(value < tmp->key){ // Go left
					if(tmp->leftChild == NULL){
						root->leftChild = newNode;
						newNode->parent = tmp; // Reference to the parent
						return 0;
					}
					tmp = tmp->leftChild;
				}
				else if(value > tmp->key){
					if(tmp->rightChild == NULL){
						root->rightChild = newNode;
						newNode->parent = tmp; // Reference to the parent
						return 0;
					}
					tmp = tmp->rightChild;
				}
				// If we have duplicate values, each of the duplicate is just as good as the last
				// Adding duplicate values just makes our tree imbalanced and ugly with no benefit.
				// Therefore, we can just ignore duplicate values.
				else{
					delete newNode; // We delete newNode to avoid a memory leak
					return -1; // If it is a duplicate value, don't add
				}
			}
		}

		void inOrderPrint(){ // Helper function to call printNode and root, since they are private
			printNode(root);
		}

		void deleteNode(int value){
			node* tmp = root;
			while(tmp != NULL){
				if(tmp->key == value){
					if((tmp->leftChild != NULL) != (tmp->rightChild != NULL)){ // != is XOR - Only then ONE of these statements is true -- NOT BOTH
						if(tmp->leftChild != NULL){ // Filling the hole with the left
							if(value < tmp->parent->key){// Left of parent
								tmp->parent->leftChild = tmp->leftChild
							}
							else{ // Right of parent
								tmp->parent->rightChild = tmp->leftChild;
							}
							tmp->leftChild->parent == tmp->parent;
						}
						else{ // Filling the hole with the right
							if(value < tmp->parent->key){// Left of parent
								tmp->parent->leftChild = tmp->rightChild
							}
							else{ // Right of parent
								tmp->parent->rightChild = tmp->rightChild;
							}
							tmp->rightChild->parent == tmp->parent;
						}
						delete tmp;
						return;
					}
					// No children case
					else if((tmp->leftChild == NULL) && (tmp->rightChild == NULL)){
						if(value < tmp->parent->key){
							tmp->parent->leftChild = NULL;
						}
						else{
							tmp->parent->rightChild = NULL:
						}
						delete tmp;
						return;
					}
					else{ // Two children
						node* rightMin = treeMinimum(tmp->rightChild); //Find the min from the right sub-tree
						if(value < tmp->parent->key){
							tmp->parent->leftChild = rightMin;
						}
						else{
							tmp->parent->rightChild = rightMin;
						}
						rightMin->parent = tmp->parent;

						//Update left child
						rightMin->leftChild = tmp->leftChild;
						tmp->leftChild->parent = rightMin;

						//Update right child
						if(rightMin->key != tmp->rightChild->key){ //First check they are not the same
							rightMin->rightChild = tmp->rightChild;
							tmp->rightChild->parent = rightMin;
						}
					}
				}
				else{
					if(value < tmp->key){
						tmp = tmp->leftChild;
					}
					else{
						tmp = tmp->rightChild;
					}
				}
			} // End of while loop

		}
};

int main(){
	BinarySearchTree bst(4);

	bst.insert(6);
	bst.insert(2);
	bst.insert(3);
	bst.insert(9);
	bst.insert(1);

	bst.inOrderPrint();

	return 0;
}