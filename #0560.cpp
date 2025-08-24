class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }
};

// optimal O(n) approach using hashmap
class Solution
{
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int presum=0;
        unordered_map<int,int> presumCount; // frequency of each presum k
        presumCount[0] = 1; // frequency of presum 0 is initialized to 1
        for(auto i:nums){
            presum += i;
            if(presumCount.find(presum - k) != presumCount.end())
                count += presumCount[presum-k];
            presumCount[presum]++;
        }
        return count;
    }
};