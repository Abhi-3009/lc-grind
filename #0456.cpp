bool find132pattern(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    int temp = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] < temp)
            return true;

        while (!st.empty() && st.top() < nums[i])
        {
            if (st.top() > temp)
                temp = st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}