private:
stack<pair<int, int>> S;

public:
StockSpanner()
{
}

int next(int price)
{

    int span = 1;
    while (!S.empty() && price >= S.top().first)
    {
        span += S.top().second;
        S.pop();
    }
    S.push({price, span});
    return span;
}