bool search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target || nums[low] == target || nums[high] == target)
            return true;

        // Handle Duplicates
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
            continue;
        }

        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (nums[high] >= target && nums[mid] < target)
                low = mid;
            else
                high = mid - 1;
        }
    }
    return false;
}