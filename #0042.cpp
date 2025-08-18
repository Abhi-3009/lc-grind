int trap(vector<int> &height)
{
    int low = 0, high = height.size() - 1;
    int lmax = 0, hmax = 0;
    int water = 0;
    while (low <= high)
    {
        if (height[low] <= height[high])
        {
            if (height[low] > lmax)
                lmax = height[low];
            else
                water += lmax - height[low];
            low++;
        }
        else
        {
            if (height[high] > hmax)
                hmax = height[high];
            else
                water += hmax - height[high];
            high--;
        }
    }
    return water;
}