int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int ans = high;
    while (low <= high)
    {
        long long k = 0;
        int mid = low + (high - low) / 2;
        for (auto i : piles)
            k += (i + mid - 1) / mid;
        if (k <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}