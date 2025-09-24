int minDepth(TreeNode *root)
{
    if (!root)
        return 0;
    int minl = 0, minr = 0;
    if (root->left)
        minl = minDepth(root->left);
    if (root->right)
        minr = minDepth(root->right);
    if (minl > 0 && minr > 0)
        return 1 + min(minl, minr);
    return 1 + max(minl, minr);
}