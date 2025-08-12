bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;
    return (log10(n) / log10(2) - floor(log10(n) / log10(2)) == 0);
}