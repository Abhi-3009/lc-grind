int firstPos(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target)
            high = mid - 1;
        else
            low = mid + 1;
        if (nums[mid] == target)
            ans = mid;
    }
    return ans;
}

int lastPos(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target)
            low = mid + 1;
        else
            high = mid - 1;
        if (nums[mid] == target)
            ans = mid;
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    return {firstPos(nums, target), lastPos(nums, target)};
}