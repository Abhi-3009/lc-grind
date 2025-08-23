int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> nse(n), pse(n);
    stack<int> st; // index stored

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while (!st.empty())
        st.pop();
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int maxRectangle = 0;
    for (int i = 0; i < n; i++)
    {
        int width = nse[i] - pse[i] - 1;
        int area = width * heights[i];
        maxRectangle = max(maxRectangle, area);
    }

    return maxRectangle;
}