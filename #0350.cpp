vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> res;

    int t1 = 0, t2 = 0;
    while (t1 < nums1.size() && t2 < nums2.size())
    {
        if (nums1[t1] < nums2[t2])
            t1++;
        else if (nums1[t1] > nums2[t2])
            t2++;
        else
        {
            res.push_back(nums1[t1]);
            t1++;
            t2++;
        }
    }
    return res;
}