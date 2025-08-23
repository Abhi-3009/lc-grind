string removeKdigits(string num, int k)
{
    int n = num.length();
    stack<char> st;
    if (k >= n)
        return "0";
    for (auto i : num)
    {
        while (!st.empty() && k > 0 && st.top() > i)
        {
            st.pop();
            k--;
        }
        st.push(i);
    }

    while (k-- && !st.empty())
        st.pop();

    string res = "";
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());

    int index = 0;
    while (index < res.size() && res[index] == '0')
        index++;
    res = res.substr(index);

    return res.empty() ? "0" : res;
}