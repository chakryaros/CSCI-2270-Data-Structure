#include <iostream>

using namespace std;

struct TreeNode {
	string key;
	TreeNode* left;
	TreeNode* right;
};

class BST{
	private:
		TreeNode* root;
		void print_tree(TreeNode*);
		TreeNode* insert_node(TreeNode*, string);
	public:
		BST();
		~BST();
		BST(string);
		void delete_node(string);
		void insert_node_helper(string);
		void print_tree_helper();
};

BST::BST(){};
BST::~BST(){};
BST::BST(string root_value)
{
	root = new TreeNode;
	root->key = root_value;
	root->left = NULL;
	root->right = NULL;
}
TreeNode* BST::insert_node(TreeNode* node, string data)
{
	if(node== NULL)  //emtpy tree
	{
		TreeNode* newnode = new TreeNode;
		newnode->key = data;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	if(data < node->key) {
		node->left = insert_node(node->left, data);
	} else {
		node->right = insert_node(node->right, data);
	}
	return node;
}
void BST::insert_node_helper(string data)
{
	insert_node(root, data);
}

void BST::print_tree(TreeNode* node)
{
	if(node == NULL) return;
	else {
		print_tree(node->left);
		cout << node->key <<" ";
		print_tree(node->right);
	}
}
void BST::print_tree_helper()
{
	print_tree(root);
	cout<<endl;
}

void BST::delete_node(string key)
{
	TreeNode* target = root; //create new node and let to the root node
	TreeNode* target_parent = NULL;
	int flag = -1;
	while((target != NULL) && (target->key != key))
	{
		target_parent = target;
		if(key < target->key)
		{
			target = target->left;
			flag = 0; //go to left
		}
		else {
			target = target->right;
			flag = 1; //go to right
		}
	}
	if(target == NULL)
	{
		cout<<" not found"<<endl;
		return;
	}

	//case 1: delete a leaf node
	if(target->left == NULL && target-> right == NULL)
	{
		// delete root node
		if(target == root)
		{
			delete root;
			root == NULL; //make empty tree we have to set root to null
		} 
		// Delete a non-root node
		else {

			//come from left
				if(flag == 0)
				{
					target_parent->left = NULL;
				}
				else
				{
					target_parent->right = NULL;
				}
				delete target;
			}
			
	}
	//case2: delete a node with only one child
	else if((target->left!=NULL) != (target->right != NULL))
	{
		if(root == target)
		{
			if(root->left !=NULL)
			{
				TreeNode* tea = root;
				root = root->left;
				delete tea;
			}
			else {
				TreeNode* tea = root;
				root = root->right;
				delete tea;
			}
		}
		else //case3: delete internal node with two kids
		{
			TreeNode* largest_node = target->left;
			while(largest_node->right !=NULL)
			{
				largest_node = largest_node->right;
				TreeNode* temp = root;
				root = root->left;
				delete temp;

			//case 3.1 deleting root
			if(target == root)
			{
				largest_node->right = root->right;
			}

			//case 3.2 deleting an internal node
			else {
				if(flag ==0)
				{
					largest_node->right = target->parent;
					largest_node->left = target->left;
					delete target;
				}
				else {
					largest_node->right = target->right;
					target->parent->right = target->left;
					delete target;
				}
			}
		}


	}

	//case3: two children
	else {
		if(root == target)
		{

		} else
		{

		}
	}
}

int main()
{
	BST demo_bst("AAA");

	demo_bst.insert_node_helper("ABC");
	demo_bst.insert_node_helper("CSS");
	demo_bst.insert_node_helper("LLL");
	demo_bst.insert_node_helper("HHH");

	demo_bst.print_tree_helper();

	return 0;
}














