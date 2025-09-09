int characterReplacement(string s, int k)
{
    int i = 0, j = 0, maxf = 0, maxl = 0;
    vector<int> freq(26, 0);
    while (j < s.length())
    {
        freq[s[j] - 'A']++;
        maxf = max(maxf, freq[s[j] - 'A']);
        if ((j - i + 1) - maxf > k)
        {
            freq[s[i] - 'A']--;
            i++;
        }
        maxl = max(maxl, j - i + 1);
        j++;
    }
    return maxl;
}