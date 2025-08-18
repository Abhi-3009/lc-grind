vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mp;
    stack<int> st;

    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        int num = nums2[i];
        while (!st.empty() && st.top() <= num)
            st.pop();
        if (st.empty())
            mp[num] = -1;
        else
            mp[num] = st.top();
        st.push(num);
    }
    vector<int> res;
    for (int num : nums1)
    {
        res.push_back(mp[num]);
    }
    return res;
}