bool isPowerOfThree(int n)
{
    if (n == 0)
        return false;
    return (log10(n) / log10(3) - floor(log10(n) / log10(3)) == 0);
}