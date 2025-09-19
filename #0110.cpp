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

// Time Complexity: O(nlogn) in worst case
// Space Complexity: O(h) where h is the height of the tree

// Optimized Approach
int depth(TreeNode *root)
{
    if (!root)
        return 0;
    int lst = depth(root->left);
    if (lst == -1)
        return -1;

    int rst = depth(root->right);
    if (rst == -1)
        return -1;

    if (abs(lst - rst) > 1)
        return -1;
    return 1 + max(lst, rst);
}

bool isBalanced(TreeNode *root)
{
    return depth(root) != -1;
}

// Time Complexity: O(n) in worst case
// Space Complexity: O(h) where h is the height of the tree