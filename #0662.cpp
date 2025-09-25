int widthOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    long long ans = 0;
    queue<pair<TreeNode *, long long>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int n = q.size();
        long long start = q.front().second;
        long long end = q.back().second;
        ans = max(ans, end - start + 1);

        for (int i = 0; i < n; i++)
        {
            auto [node, idx] = q.front();
            q.pop();
            idx -= start;
            if (node->left)
                q.push({node->left, 2 * idx});
            if (node->right)
                q.push({node->right, 2 * idx + 1});
        }
    }
    return ans;
}