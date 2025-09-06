int longestOnes(vector<int> &nums, int k)
{
    int left = 0, maxlen = 0;
    int zeroes = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
            zeroes++;
        while (zeroes > k)
        {
            if (nums[left] == 0)
                zeroes--;
            left++;
        }
        maxlen = max(maxlen, right - left + 1);
    }
    return maxlen;
}