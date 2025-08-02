int reverse(int x)
{
    long rev_no = 0;
    int unit;
    while (x != 0)
    {
        unit = x % 10;
        rev_no = (rev_no * 10) + unit;
        x = x / 10;
    }

    if (rev_no > INT_MAX || rev_no < INT_MIN)
        return 0;
    return (int)rev_no;
}