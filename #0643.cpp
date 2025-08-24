double findMaxAverage(vector<int> &nums, int k)
{
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < k; i++)
        sum += nums[i];
    int maxsum = sum;
    for (int i = k; i < n; i++)
    {
        sum -= nums[i - k];
        sum += nums[i];
        maxsum = max(maxsum, sum);
    }
    return (double)maxsum / k;
}