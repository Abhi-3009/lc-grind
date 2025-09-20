int pre = 0;
unordered_map<int, int> ino;
TreeNode *helper(vector<int> &preorder, int left, int right)
{
    if (left > right)
        return nullptr;

    int rootval = preorder[pre++];
    TreeNode *root = new TreeNode(rootval);

    int mid = ino[rootval];
    root->left = helper(preorder, left, mid - 1);
    root->right = helper(preorder, mid + 1, right);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int size = inorder.size();
    for (int i = 0; i < size; i++)
        ino[inorder[i]] = i;

    return helper(preorder, 0, size - 1);
}