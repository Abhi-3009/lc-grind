int diameter = 0;
int depth(TreeNode *root)
{
    if (!root)
        return 0;
    int lst = depth(root->left);
    int rst = depth(root->right);
    diameter = max(diameter, lst + rst);
    return 1 + max(lst, rst);
}

int diameterOfBinaryTree(TreeNode *root)
{
    int maxl = depth(root);
    return diameter;
}