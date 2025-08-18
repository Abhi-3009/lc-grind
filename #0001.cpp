class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i, j;
        vector<int> result;
        for (i = 0; i < nums.size(); i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if ((nums[i] + nums[j]) == target)
                    result = {i, j};
            }
        }
        return result;
    }
};

// optimal solution
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            if (mp.count(comp))
                return {mp[comp], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};

// optimal solution using two pointers
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == target)
            {
                result = {left, right};
                return result;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return result;
    }
};