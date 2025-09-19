int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;

    int maxh = 1, lsh = 1, rsh = 1;
    if (!root->left && !root->right)
    {
        return max(lsh, rsh);
    }
    else
    {
        if (root->left)
            lsh += maxDepth(root->left);
        if (root->right)
            rsh += maxDepth(root->right);
        maxh = max(lsh, rsh);
    }
    return maxh;
}