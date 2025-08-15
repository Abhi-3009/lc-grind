bool isValid(string s)
{
    stack<int> st;
    for (auto i : s)
    {
        if (i == '(' || i == '{' || i == '[')
            st.push(i);
        else
        {
            if (st.empty())
                return false;
            char top = st.top();
            if ((i == ')' && top == '(') || (i == ']' && top == '[') ||
                (i == '}' && top == '{'))
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}