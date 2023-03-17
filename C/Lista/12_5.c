#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    long long int num, count2, count3, i, flag;
    for (num = 2; num <= 100; num++)
    {
        count2 = count3 = 0;
        i = num;
        flag = 0;
        while (i != 1 && !flag)
        {
            if (i % 2 == 0)
            {
                i = i / 2;
                count2++;
            }
            else if (i % 3 == 0)
            {
                i = i / 3;
                count3++;
            }
            else
            {
                flag = 1;
            }
        }
        if (!flag)
        {
            printf("%lld = 2^%lld * 3^%lld\n", num, count2, count3);
        }
    }
    return 0;
}
