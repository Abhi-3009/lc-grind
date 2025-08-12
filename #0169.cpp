int majorityElement(vector<int> &nums)
{
    int key = nums[0];
    int count = 0;
    for (auto i : nums)
    {
        if (i == key)
            count++;
        else
        {
            count--;
            if (count < 0)
            {
                key = i;
                count = 0;
            }
        }
    }
    return key;
}