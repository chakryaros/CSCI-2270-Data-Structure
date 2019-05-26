#include <iostream>

using namespace std;

struct node{
	int key;
	node* parent;
	node* leftChild;
	node* rightChild;
};

class BST {
private:
	node* root;
	void AddLeafPrivate(int key, node* ptr)
	{
		if(root==NULL)
		{
			root = CreateLeaf(key);
		}
		else if (key < ptr->key)
		{
			if(ptr->leftChild !=NULL)
			{
				AddLeafPrivate(key, ptr->leftChild);
			}
			else
			{
				ptr->leftChild = CreateLeaf(key);
			}
		}
		else if (key > ptr->key)
		{
			if(ptr->rightChild !=NULL)
			{
				AddLeafPrivate(key, ptr->rightChild);
			}
			else
			{
				ptr->rightChild = CreateLeaf(key);
			}
		}
		else
		{
			cout<<"key "<< key << " has already added to tree\n";
		}
	}
	void printInOrderPrivate(node* ptr)
	{
		if(root!=NULL)
		{
			if(ptr->leftChild != NULL)
			{
				printInOrderPrivate(ptr->leftChild);
			}
			cout<< ptr->key <<" ";
			if(ptr->rightChild !=NULL)
			{
				printInOrderPrivate(ptr->rightChild);
			}
		}
		else
		{
			cout<<"The tree is empty\n";
		}
	}
	node* ReturnNodePrivate(int key, node* ptr)
	{
		if(ptr != NULL)
		{
			if(ptr->key == key)
			{
				return ptr;
			}
			else
			{
				if( key < ptr->key)
				{
					return ReturnNodePrivate(key, ptr->leftChild);
				}
				else
				{
					return ReturnNodePrivate(key, ptr->rightChild);
				}
			}
		}
		else
		{
			return NULL;
		}
	}
	int FindSmallestPrivate(node* ptr)
	{
		if(root == NULL)
		{
			cout<<"The tree is empty\n";
			return -1000;
		}
		else
		{
			if(ptr->leftChild !=NULL)
			{
				return FindSmallestPrivate(ptr->leftChild);
			}
			else
			{
				return ptr->key;
			}
		}
	}
	void substractLeafPrivate(node* ptr) //substract 1 from leaf node
	{
		//ptr = root;
		if(ptr->leftChild ==NULL && ptr->rightChild == NULL)
		{
			ptr->key = (ptr->key) -1;
		}
		else
		{
			if(ptr->leftChild != NULL)
			{
				substractLeafPrivate(ptr->leftChild);
			}

			if(ptr->rightChild !=NULL)
			{
				substractLeafPrivate(ptr->rightChild);
			}
		}
	}
	void removeNodePrivate(int key, node* parent)
	{
		if(root !=NULL)
		{
			if(root->key == key)
			{
				RemoveRootMatch();
			}
			else
			{
				if( key < parent->key && parent->leftChild !=NULL)
				{
					//current left child matach key
					parent->leftChild->key == key ?
					//if it find, call reomoveMatch function
					RemoveMatch(parent, parent->leftChild, true) :

					//if not. call the removeNodePrivate to recusive to left
					removeNodePrivate(key, parent->leftChild);
				}
				else if( key > parent->key && parent->rightChild !=NULL)
				{
					parent->rightChild->key == key ?
					RemoveMatch(parent, parent->rightChild, false) :
					removeNodePrivate(key, parent->rightChild);
				}
				else
				{
					cout<<"The key "<< key <<"was not found in the tree.\n";
				}
			}
		} else {
			cout<<"The tree is empty.\n";
		}
	}
	void RemoveRootMatch()
	{
		if(root !=NULL)
		{
			node* temp = root;
			int rootkey = root->key;
			int smallestInRightSubstree;
			//cass0 - 0 children
			if(root->leftChild == NULL && root->rightChild == NULL)
			{
				root = NULL;
				delete temp;
			}

			// case1 - 1 child
			else if(root->leftChild == NULL && root->rightChild != NULL)
			{
				root = root->rightChild;
				temp->rightChild = NULL;
				delete temp;
				cout<<"The root node with key "<< rootkey<<"was deleted. "<<
					"The new root contain key " << root->key <<endl;
			}
			else if(root->leftChild != NULL && root->rightChild == NULL)
			{
				root = root->leftChild;
				temp->leftChild = NULL;
				delete temp;
				cout<<"The root node with key "<< rootkey<<"was deleted. "<<
					"The new root contain key " << root->key <<endl;
			}

			// cass2 - 2 children
			else
			{
				smallestInRightSubstree = FindSmallestPrivate(root->rightChild);
				removeNodePrivate(smallestInRightSubstree, root);
				root->key = smallestInRightSubstree;
				cout<<"The root node with key "<< rootkey<<"was deleted. "<<
					"The new root contain key " << root->key <<endl;
			}
		}
		else
		{
			cout<<"Can not remove root. The tree is empty\n";
		}
	}
	void RemoveMatch(node* parent, node* match, bool left)
	{
		if(root !=NULL)
		{
			node* temp;
			int matchkey = match->key;
			int smallestInRightSubstree;

			//case0 -0 children
			if( match->leftChild == NULL && match->rightChild == NULL)
			{
				temp = match;
				left == true ? parent->leftChild = NULL : parent->rightChild =NULL;
				delete temp;
				cout<<"The node containing key "<< matchkey <<" was removed.\n";
			}

			//case1- 1 child
			else if(match->leftChild == NULL && match->rightChild != NULL)
			{
				left == true ? parent->leftChild = match->rightChild : parent->rightChild = match->rightChild ;
				match->rightChild = NULL;
				temp = match;
				delete temp;
				cout<<"The node containing key "<< matchkey <<" was removed.\n";
			}
			else if(match->leftChild != NULL && match->rightChild == NULL)
			{
				left == true ? parent->leftChild = match->leftChild : parent->rightChild = match->leftChild ;
				match->leftChild = NULL;
				temp = match;
				delete temp;
				cout<<"The node containing key "<< matchkey <<" was removed.\n";
			}
			//cass2 - 2 children
			else
			{
				smallestInRightSubstree = FindSmallestPrivate(match->rightChild);
				removeNodePrivate(smallestInRightSubstree, match);
				match->key = smallestInRightSubstree;
			}
		}
		else
		{
			cout<<"can not remove match.\n";
		}
	}
public:
	BST(){
		root = NULL;
	}
	node* CreateLeaf(int key)
	{
		node* n = new node;
		n->key = key;
		n->parent=NULL;
		n->leftChild=NULL;
		n->rightChild =NULL;
		return n;
	}
	void Addleaf(int key)
	{
		AddLeafPrivate(key, root);
	}
	void printInOrder()
	{
		printInOrderPrivate(root);
		cout<<endl;
	}
	node* ReturnNode(int key)
	{
		return ReturnNodePrivate(key, root);
	}
	int FindSmallest()
	{
		return FindSmallestPrivate(root);
	}
	void substractLeaf()
	{
		substractLeafPrivate(root);
	}

	int ReturnRootKey()
	{
		if(root !=NULL)
		{
			return root->key;
		}
		else
		{
			return -1000;
		}
	}

	void PrintChildren(int key)
	{
		node* Ptr = ReturnNode(key);
		if( Ptr != NULL)
		{
			cout<<"Parent Node = " << Ptr->key <<endl;
			
			Ptr->leftChild == NULL ? //bool for true or false
			//if left pointer point to  null
			cout << "Left Child = NULL.\n" :
			//if left pointer point to sth
			cout<< "Left Child = "<< Ptr->leftChild->key <<endl;

			Ptr->rightChild == NULL ? //bool for true or false
			//if left pointer point to  null
			cout << "Right Child = NULL.\n" :
			//if left pointer point to sth
			cout<< "Right Child = "<< Ptr->rightChild->key <<endl;
		}
		else
		{
			cout <<"Key "<< key << " is not in the tree.\n";
		}
	}
	void removeNode(int key)
	{
		removeNodePrivate(key, root);
	}
	
};

int main()
{
	int arr[4] = {7, 5,9, 3};
	int TreeKeys[16]= {50, 76, 21,4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
	BST newtree;
	cout<<"Print the tree in order\nBefore adding number\n";
	newtree.printInOrder();
	for(int i=0; i<16; i++)
	{
		newtree.Addleaf(TreeKeys[i]);
	}
	cout<<"Print the tree in order\nAfter adding number\n";
	newtree.printInOrder();
	cout<<"The smalles value in the tree is "<<newtree.FindSmallest()<<endl;

	newtree.substractLeaf();
	cout<<"After substract one from leaf: ";
	newtree.printInOrder();

	//newtree.PrintChildren(newtree.ReturnRootKey());

	//print all children in the treekey array
	for(int i=0; i<16; i++)
	{
		newtree.PrintChildren(TreeKeys[i]);
		cout<<endl; 
	}

	newtree.removeNode(15);

	

	return 0;

}