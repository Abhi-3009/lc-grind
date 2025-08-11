int findMaxConsecutiveOnes(vector<int> &nums)
{
    int count = 0, count_max = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i])
            count++;
        else
        {
            if (count > count_max)
                count_max = count;
            count = 0;
        }
    }
    if (count > count_max)
        count_max = count;
    return count_max;
}