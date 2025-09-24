bool helper(TreeNode *p, TreeNode *q)
{
    if (!p && !q)
        return true;
    if (!p || !q)
        return false;
    if (p->val != q->val)
        return false;

    return helper(p->left, q->right) && helper(p->right, q->left);
}

bool isSymmetric(TreeNode *root)
{
    return helper(root->left, root->right);
}