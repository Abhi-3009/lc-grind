string largestGoodInteger(string num)
{
    string maxstr = "";
    int n = num.length();
    for (int i = 0; i <= n - 3; i++)
    {
        if (num[i] == num[i + 1] && num[i] == num[i + 2])
        {
            string str = num.substr(i, 3);
            if (str > maxstr)
                maxstr = str;
        }
    }
    return maxstr;
}