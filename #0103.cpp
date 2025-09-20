vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        level++;
        int levelsize = q.size();
        vector<int> li;

        for (int i = 0; i < levelsize; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            li.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        if (level % 2 == 0)
            reverse(li.begin(), li.end());
        ans.push_back(li);
    }

    return ans;
}