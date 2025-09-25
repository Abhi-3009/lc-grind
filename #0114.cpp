void flatten(TreeNode *root)
{
    if (!root)
        return;
    TreeNode *f = root;
    TreeNode *r = root->left;
    if (r)
    {
        flatten(r);
        TreeNode *temp = f->right;
        f->right = r;
        f->left = NULL;

        while (f->right)
            f = f->right;
        f->right = temp;
    }
    flatten(root->right);
}