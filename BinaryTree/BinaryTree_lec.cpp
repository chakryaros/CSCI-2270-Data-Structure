#include <iostream>

using namespace std;

struct node {
	int key;
	node* parent;
	node* leftChild;
	node* rightChild;
};

class BinarySearchTree {
	private:
		node* root;
		node* searhRecursive(node* n, int value) {
			if( n== NULL) {
				return NULL;
			}
			if(value == n->key) //if value equal to n root
			{
				return n;
			} else if (value < n->key)
			{
				return searhRecursive(n->leftChild, value);
			} else if (value > n->key) 
			{
				return searhRecursive(n->rightChild, value);
			}
		}

		void printNode(node* n) //in order traverse
		{
			if( n == NULL)
			{
				return;
			}
			if(n->leftChild!=NULL)
			{
				printNode(n->leftChild);
			}
			cout<< n->key <<" ";
			if(n->rightChild!=NULL)
			{
				printNode(n->rightChild);
			}
			//cout<< n->key <<" " if we cout here, it mean that we print the all 
			//the children before the parent
		}
		node* treeMinmum(node* n)
		{
			while(n->leftChild !=NULL)
			{
				n = n->leftChild;
			}
			return n;
		}
		void deleteTreePrivate(node* n)
		{
			if( n == NULL)
			{
				return;
			}
			if(n->leftChild != NULL) // delete all left children
			{
				deleteTreePrivate(n->leftChild);
			}
			if(n->rightChild !=NULL) // delete all right children
			{
				deleteTreePrivate(n->rightChild);
			}
			if (root == n) {
				root = NULL;
			}
			delete n;
		}
	public:
		BinarySearchTree( int k) {
			root = new node;
			root->key = k;
			root->parent= NULL;
			root->leftChild=NULL;
			root->rightChild= NULL;
		}
		~BinarySearchTree()
		{
			delete root;
		}
		int insert(int value)
		{
			// initialize new node
			node* newNode = new node;
			newNode->key = value;
			newNode->parent = NULL;
			newNode->leftChild=NULL;
			newNode->rightChild=NULL;

			//find out where it goes
			node* temp = root;
			while(1) {
				if(value < temp->key) { // go left
					if(temp->leftChild==NULL) {
						temp->leftChild = newNode;
						newNode->parent = temp;
						return 0;
					}
					temp = temp->leftChild;
					
				} else if (value > temp->key) { // go right
					if(temp->rightChild==NULL)
					{
						temp->rightChild = newNode;
						newNode->parent = temp;
						return 0;
					}
					temp = temp->rightChild;
				}
				else { //duplicate value
					delete newNode;
					return -1;
				}
			}
		}
		void inOrderPrint()
		{
			printNode(root);
		}
		node* search(int value)
		{
			return searhRecursive(root, value);
		}
		void deleteTree()
		{
			deleteTreePrivate(root);
		}
		// void deleteNode(int value)
		// {
		// 	node* temp = root;
		// 	while(temp!=NULL)
		// 	{
		// 		if(temp->key==value)
		// 		{
		// 			if((temp->leftChild!=NULL) != (temp->rightChild!=NULL))
		// 			{
		// 				if(temp->leftChild !=NULL)
		// 				{
		// 					if(value < temp->parent->key) {
		// 						temp->parent->leftChild = temp->leftChild;
		// 					} else {
		// 						temp->parent->rightChild = temp->leftChild;
		// 					}
		// 					temp->leftChild->parent = temp->parent;
		// 				}
		// 			}
		// 		} else {
		// 			if(value < temp->key)
		// 			{
		// 				temp = temp->rightChild;
		// 			} else {
		// 				temp = temp->rightChild;
		// 			}
		// 		}
		// 	}
		// }
};

int main()
{
	BinarySearchTree bst(4);

	bst.insert(6);
	bst.insert(2);
	bst.insert(9);
	bst.insert(3);
	bst.insert(1);

	node* net = bst.search(2);
	if(net!=NULL)
	{
		cout<<"Found key: "<<net->key<<endl;
	} else
	{
		cout<<"Key not found!\n";
	}
	cout<<"before delete\n";
	bst.inOrderPrint();
	cout<<endl;

	bst.deleteTree();
	cout<<"After delete: "<<endl;
	bst.inOrderPrint();

	return 0;
}













