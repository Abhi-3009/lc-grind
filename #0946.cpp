bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> st;
    int i = 0;
    int p1_size = pushed.size();
    int p2_size = popped.size();
    for (int j = 0; j < p2_size; j++)
    {
        if (!st.empty() && st.top() == popped[j])
            st.pop();
        else
        {
            while (i < p1_size && pushed[i] != popped[j])
            {
                st.push(pushed[i]);
                i++;
            }
            if (i == p1_size && !st.empty())
                return false;
            i++;
        }
    }
    return true;
}