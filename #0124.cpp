int maxPathSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    helper(root, maxSum);
    return maxSum;
}

int helper(TreeNode *root, int &maxSum)
{
    if (!root)
        return 0;

    int ls = max(0, helper(root->left, maxSum));
    int rs = max(0, helper(root->right, maxSum));

    maxSum = max(maxSum, root->val + ls + rs);
    return root->val + max(ls, rs);
}