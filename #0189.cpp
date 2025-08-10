void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
}

// optimal solution
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = nums[i];
    }
    nums = temp;
}