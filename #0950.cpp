vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    int n = deck.size();
    vector<int> res;
    sort(deck.begin(), deck.end());
    deque<int> dq;
    dq.push_front(deck[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        int it = dq.back();
        dq.pop_back();
        dq.push_front(it);
        dq.push_front(deck[i]);
    }

    while (!dq.empty())
    {
        int it = dq.front();
        dq.pop_front();
        res.push_back(it);
    }
    return res;
}