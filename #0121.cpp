int maxProfit(vector<int> &prices)
{
    int i = 0, n = prices.size();
    int max = 0;
    for (int j = 1; j < n; j++)
    {
        if (prices[j] < prices[i])
            i = j;
        if (prices[j] - prices[i] > max)
            max = prices[j] - prices[i];
    }
    return max;
}