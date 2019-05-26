#include <iostream>

using namespace std;

struct TreeNode
{
int key;
TreeNode *left;
TreeNode *right;
TreeNode *parent;
};


TreeNode* treeMinimum(TreeNode* n)
{
    while(n->right!=NULL)
    {
        n = n->right;
    }
    return n;
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

void DeleteNodeWithLeftChild(TreeNode *thenode)
{
    TreeNode* temp = thenode->left;
    TreeNode* rightMax = treeMinimum(temp);
    if(thenode->left !=NULL)
    {
        if(thenode->parent->left == thenode)
        {
            
            TreeNode* maxParent = rightMax->parent;
            //cout<<"maxparetn"<<maxParent->key<<endl;
            if(temp->right==rightMax)
            {
                thenode->parent->left = rightMax;
                temp->right = rightMax->left;
                rightMax->left = temp;
                rightMax->parent = thenode->parent;
            }
            else
            {
                thenode->parent->left = rightMax;
                maxParent->right = rightMax->left;
                rightMax->left = temp;
                rightMax->parent = thenode->parent;
                //delete thenode;
                
            }
        }
        else if(thenode->parent->right == thenode)
        {
           thenode->parent->right = rightMax;
           rightMax->left = temp;
           temp->right = NULL;
           //cout<<"temp "<<temp->key<<endl;
           rightMax->parent = thenode->parent;
        }
        delete thenode;
    }
}

// void DeleteNodeWithLeftChild(TreeNode *thenode)
// {
//     TreeNode* temp = thenode->left;
//    // if(temp ==NULL)
//     //{
//         if(thenode->parent != NULL)
//         {
//             if(thenode->key < thenode->parent->key)
//             {
//                 thenode->parent->left = temp;
//             }
//             else
//             {
//                 thenode->parent->right = temp;
//             }
//         }
//         delete thenode;
//         return;
//     //}
//     while(temp->right!=NULL)
//     {
//         temp = temp->right;
//     }

//     if(thenode->left != temp)
//     {
//         temp->left = thenode->left;
//         temp->parent->right = NULL;
//     }
//     temp->parent = thenode->parent;
//     temp->right = thenode->right;

// }



int main()
{
	int a[] = {7,9,5,2,1,4,3};
    int length = 7;
    int value = 5;
	return 0;
}












