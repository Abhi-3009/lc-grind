int cameras = 0;

int checkCameras(TreeNode *root)
{
    if (!root)
        return 2;
    int left = checkCameras(root->left);
    int right = checkCameras(root->right);

    if (left == 0 || right == 0)
    {
        cameras++;
        return 1;
    }

    if (left == 1 || right == 1)
        return 2;

    return 0;
}

int minCameraCover(TreeNode *root)
{
    if (checkCameras(root) == 0)
        cameras++;
    return cameras;
}