int helper(TreeNode *node, int &lpath)
{
    if (!node)
        return 0;
    int left = helper(node->left, lpath);
    int right = helper(node->right, lpath);

    int leftCheck = 0, rightCheck = 0;
    if (node->left && node->val == node->left->val)
        leftCheck = left + 1;
    if (node->right && node->val == node->right->val)
        rightCheck = right + 1;

    lpath = max(lpath, leftCheck + rightCheck);
    return max(leftCheck, rightCheck);
}

int longestUnivaluePath(TreeNode *root)
{
    int lpath = 0;
    helper(root, lpath);
    return lpath;
}