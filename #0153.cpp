int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = -1;

    if (n == 2)
        return min(nums[0], nums[1]);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid == 0 || nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
        {
            ans = nums[mid];
            break;
        }
        else if (mid == n - 1 || nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
            ans = nums[(mid + 1) % n];
            break;
        }
        else if (nums[high] > nums[mid])
            high = mid;
        else
            low = mid;
    }
    return ans;
}