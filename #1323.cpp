int maximum69Number(int num)
{
    int temp, count = 0, max = num;
    for (int i = num; i > 0; i /= 10)
    {
        int z = i % 10;
        if (z == 9)
        {
            count++;
            continue;
        }
        else
        {
            temp = num + 3 * pow(10, count);
            if (temp > max)
                max = temp;
            count++;
        }
    }
    return max;
}