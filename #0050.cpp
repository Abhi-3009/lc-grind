double myPow(double x, int n)
{
    long long exp = n;
    if (exp < 0)
    {
        x = 1 / x;
        exp = -exp;
    }
    double power = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            power *= x;
        x *= x;
        exp /= 2;
    }
    return power;
}