vector<int> sumZero(int n)
{
    vector<int> ans(n, 0);
    int x = 1, i = 0;
    if (n == 1)
        return {0};
    while (i < n - 1)
    {
        if (n % 2 == 0)
        {
            ans[i++] = x;
            ans[i++] = -x;
            x++;
        }
        else
        {
            ans[0] = 0;
            ans[++i] = x;
            ans[++i] = -x;
            x++;
        }
    }
    return ans;
}