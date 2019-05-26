void addNumberToLeaf(TreeNode* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        root->val = (root->val) + 2;
    }
    else
    {
        if(root->left != NULL)
        {
            func(root->left);
        }
        if(root->right !=NULL)
        {
            func(root->right);
        }
    }
}