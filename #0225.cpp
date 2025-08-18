class MyStack
{
public:
    queue<int> q;
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 1; i < q.size(); i++)
        {
            q.push(top());
            q.pop();
        }
    }

    int pop()
    {
        int val = q.front();
        q.pop();
        return val;
    }

    int top()
    {
        int top = q.front();
        return top;
    }

    bool empty()
    {
        return q.empty();
    }
};