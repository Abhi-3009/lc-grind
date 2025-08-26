vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
            continue;
        for (int k = n - 1; k > i; k--)
        {
            if (k < n - 1 && nums[k] == nums[k + 1])
                continue;
            int j = i + 1;
            int l = k - 1;
            while (j < l)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[k];
                if (sum < target)
                    j++;
                else if (sum > target)
                    l--;
                else
                {
                    res.push_back({nums[i], nums[j], nums[l], nums[k]});
                    j++;
                    l--;
                    while (j < l && nums[j - 1] == nums[j])
                        j++;
                    while (j < l && nums[l] == nums[l + 1])
                        l--;
                }
            }
        }
    }
    return res;
}