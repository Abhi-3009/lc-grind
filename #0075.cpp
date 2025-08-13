void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
            mid++;
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// optimal solution for sorting colors in a single pass
// Dutch National Flag problem
// Time complexity: O(n)
// Space complexity: O(1)
// This function sorts an array containing only 0s, 1s, and 2s in-place.