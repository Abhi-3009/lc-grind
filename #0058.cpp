int lengthOfLastWord(string s)
{
    int n = s.size();
    int i = n - 1, count = 0;
    while (s[i] == ' ')
        i--;
    for (; i >= 0 && s[i] != ' '; i--)
        count++;
    return count;
}