int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int elem;
    if (n == 1)
        return nums[0];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid == 0 || nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];
        if (mid % 2 == 0)
        {
            if (nums[mid - 1] == nums[mid])
                high = mid - 1;
            else if (nums[mid] == nums[mid + 1])
                low = mid + 1;
            else
                elem = nums[mid];
        }
        else
        {
            if (nums[mid - 1] == nums[mid])
                low = mid + 1;
            else if (nums[mid] == nums[mid + 1])
                high = mid - 1;
            else
                elem = nums[mid];
        }
    }
    return elem;
}