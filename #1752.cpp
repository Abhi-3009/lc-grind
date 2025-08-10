bool check(vector<int> &nums)
{
    int i, x;
    for (i = 1; i < nums.size(); i++)
    {
        if (nums[i] >= nums[i - 1])
        {
        }
        else
        {
            for (x = i; x < nums.size() - 1; x++)
            {
                if (nums[x] <= nums[x + 1])
                {
                }
                else
                {
                    return false;
                }
            }
            if (nums[x] > nums[0])
                return false;
        }
    }
    return true;
}