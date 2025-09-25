int ldepth(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + ldepth(root->left);
}

int rdepth(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + rdepth(root->right);
}

int countNodes(TreeNode *root)
{
    if (!root)
        return 0;
    int left = ldepth(root);
    int right = rdepth(root);

    if (left == right)
        return (1 << left) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}