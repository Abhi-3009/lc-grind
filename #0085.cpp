int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty())
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    int maxarea = 0;
    vector<vector<int>> psum(n, vector<int>(m));

    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] == '1')
                sum += 1;
            else
                sum = 0;
            psum[i][j] = sum;
        }
    }
    for (int i = 0; i < n; i++)
        maxarea = max(maxarea, largestRectangle(psum[i]));

    return maxarea;
}

int largestRectangle(vector<int> &h)
{
    int n = h.size();
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int minH = h[i];
        for (int j = i; j < n; j++)
        {
            minH = min(minH, h[j]);
            maxArea = max(maxArea, minH * (j - i + 1));
        }
    }
    return maxArea;
}