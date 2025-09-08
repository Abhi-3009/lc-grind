class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        int x = 1, y = n - 1;
        while (to_string(y).find('0') != string::npos || to_string(x).find('0') != string::npos)
        {
            x++;
            y--;
        }
        return {x, y};
    }
};