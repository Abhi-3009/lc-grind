int maxFreqSum(string s)
{
    // Count array for all letters
    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'a']++;
    }

    int maxVowel = 0;
    int maxConsonant = 0;

    auto isVowel = [](char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };

    for (int i = 0; i < 26; i++)
    {
        char c = 'a' + i;
        if (isVowel(c))
        {
            maxVowel = max(maxVowel, freq[i]);
        }
        else
        {
            maxConsonant = max(maxConsonant, freq[i]);
        }
    }

    return maxVowel + maxConsonant;
}