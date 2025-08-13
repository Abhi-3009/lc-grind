int maxSubArray(vector<int> &nums)
{
    int sum = 0, maxsum = INT_MIN;
    for (auto i : nums)
    {
        if (sum < 0)
            sum = 0;
        sum += i;
        if (sum > maxsum)
            maxsum = sum;
    }
    return maxsum;
}