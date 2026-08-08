#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    int i, j;

    int center = n / 2;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j || i + j == n - 1)
            {
                int d = abs(i - center);
                int val = 10 * (center - d + 1);
                printf("%2d ", val);
            }
            else
                printf(" 0 ");
        }
        printf("\n");
    }

    return 0;
}

