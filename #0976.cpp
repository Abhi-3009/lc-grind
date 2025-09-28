int largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] + nums[i - 1] > nums[i - 2])
            return nums[i] + nums[i - 1] + nums[i - 2];
    }
    return 0;
}