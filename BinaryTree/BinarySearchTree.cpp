#include <iostream>

using namespace std;

struct TreeNode {
	string key;
	TreeNode* left;
	TreeNode* right;
};

class BST {
private:
	TreeNode* root;
	void print_tree(TreeNode*);
	TreeNode* insert_node(TreeNode*, string);
public:
	BST();
	~BST();
	BST(string);
	void delete_node(string);
	void print_tree_helper();
	void insert_node_helper(string data);
};

BST::BST() {};
BST::~BST() {};
BST::BST(string root_value)
{
	root = new TreeNode;
	root->key = root_value;
	root->left = NULL;
	root->right = NULL;
}
TreeNode* BST::insert_node(TreeNode* node, string data)
{
	if(node==NULL)
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
void BST::print_tree(TreeNode* node){
	if(node==NULL) return;
	else {
	  print_tree(node->left);
	  cout<< node->key << " ";
	  print_tree(node->right);
	}
}
void BST::print_tree_helper(){
	print_tree(root);
	cout<<endl;
}

int main()
{
 	BST demo_bst("HAA");
	demo_bst.insert_node_helper("ABC");
	demo_bst.insert_node_helper("AAA");
	
	demo_bst.print_tree_helper();
	return 0;
}
