int fib(int n)
{
    if (n < 2)
        return n;
    int f1 = 0, f2 = 1;
    for (int i = 2; i < n; i++)
    {
        int temp = f2;
        f2 = f1 + f2;
        f1 = temp;
    }
    return f1 + f2;
}