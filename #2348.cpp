long long zeroFilledSubarray(vector<int> &nums)
{
    long long count = 0, consZero = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            consZero++;
            continue;
        }
        else
        {
            count += (consZero * (consZero + 1)) / 2;
            consZero = 0;
        }
    }
    if (nums[n - 1] == 0)
        count += (consZero * (consZero + 1)) / 2;
    return count;
}