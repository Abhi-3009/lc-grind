int missingNumber(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int N = (nums.size() * (nums.size() + 1)) / 2;

    return N - sum;
}