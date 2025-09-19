int depth(TreeNode *root)
{
    if (!root)
        return 0;
    int lst = depth(root->left);
    int rst = depth(root->right);
    return 1 + max(lst, rst);
}

bool isBalanced(TreeNode *root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    int lst = depth(root->left);
    int rst = depth(root->right);
    if (abs(lst - rst) > 1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}