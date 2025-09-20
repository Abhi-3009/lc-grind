int sum = 0;
bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    sum += root->val;
    if (!root->left && !root->right)
    {
        if (sum == targetSum)
            return true;
        sum -= root->val;
        return false;
    }

    bool left = hasPathSum(root->left, targetSum);
    bool right = hasPathSum(root->right, targetSum);
    sum -= root->val;
    return left || right;
}

// recursion
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // If it's a leaf node, check if path sum matches
        if (!root->left && !root->right) 
            return targetSum == root->val;

        // Recurse left or right with reduced target
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
