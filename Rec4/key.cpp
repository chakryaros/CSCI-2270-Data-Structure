
#include <iostream>

using namespace std;


struct TreeNode {
   int key;
   TreeNode* left;
   TreeNode* right;
};


class BST {
    private:
        TreeNode* root;

        void print_tree(TreeNode*);
        TreeNode* insert_node(TreeNode*, int);

    public:
        BST();
        BST(int);
        ~BST();
        void delete_node(int);
        void insert_node_helper(int);
        void print_tree_helper();
};


BST::BST(){}
BST::~BST(){}
BST::BST(int root_value) {
    root = new TreeNode;
    root->key = root_value;
    root->left = NULL;
    root->right = NULL;
}


TreeNode* BST::insert_node(TreeNode* node, int data) {
    if (node == NULL) {
        TreeNode* newnode = new TreeNode;
        newnode->key = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    if (data < node->key) node->left = insert_node(node->left, data);
    else node->right = insert_node(node->right, data);
    return node;
}

void BST::insert_node_helper(int data) {
    insert_node(root, data);
}

void BST::print_tree(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    else {
        print_tree(node->left);
        cout << node->key << " ";
        print_tree(node->right);
    }
}

void BST::print_tree_helper() {
    print_tree(root);
}


void BST::delete_node(int key) {
    TreeNode* target = root;
    TreeNode* target_parent = NULL;

    int flag = -1;
    while ((target != NULL) && (target->key != key)) {
        target_parent = target;
        if (key < target->key) {
            target = target->left;
            flag = 0;
        }
        else {
            target = target->right;
            flag = 1;
        }
    }
    // The key is not in the tree
    if (target == NULL) {
        cout << "Nothing to be deleted." << endl;
        return;
    }




    // Found the node to be deleted.

    // Case 1: delete a leaf node
    if (target->left == NULL && target->right == NULL) {
        // Deleting the root node
        if (target_parent == NULL) {
            delete root;
            root = NULL;
        }
        else {
            if (flag == 0) target_parent->left = NULL;
            else target_parent->right = NULL;
            delete target;
        }
    }
    // Case 2: delete internal nodes with one kid
    // else if (target->left == NULL || target->right == NULL) {
    else if ((target->left != NULL) != (target->right != NULL)) {
        if (target_parent == NULL) {
            if (target->left != NULL) {
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
        else {
            if (flag == 0) {
                if (target->left != NULL) target_parent->left = target->left;
                else target_parent->left = target->right;
                delete target;
            }
            else {
                if (target->left != NULL) target_parent->right = target->left;
                else target_parent->right = target->right;
                delete target;

            }
        }
    }
    // // Case 3: delete internal nodes with two kids
    else {
        TreeNode* largest_node = target->left;
        while (largest_node->right != NULL) {
            largest_node = largest_node->right;
        }
        // Deleting the root node
        if (target_parent == NULL) {
            TreeNode* tea = root;
            root = tea->left;
            largest_node->right = tea->right;
            delete tea;
        }
        else {
            if (flag == 0) {
                target_parent->left = target->left;
                largest_node->right = target->right;
            }
            else {
                target_parent->right = target->left;
                largest_node->right = target->right;
            }
            delete target;
        }
    }
}


int main(int argc, char const *argv[]) {
    

    BST demo_bst(16);
    demo_bst.print_tree_helper();

    cout << endl;

    demo_bst.insert_node_helper(12);
    demo_bst.insert_node_helper(11);
    demo_bst.insert_node_helper(14);
    demo_bst.insert_node_helper(13);
    demo_bst.insert_node_helper(15);
    demo_bst.insert_node_helper(19);
    demo_bst.insert_node_helper(18);
    demo_bst.insert_node_helper(20);

    demo_bst.print_tree_helper();

    cout << endl;

    demo_bst.delete_node(19);
    demo_bst.print_tree_helper();

    cout << endl;


    return 0;
}

