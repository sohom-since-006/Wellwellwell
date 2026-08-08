#include<stdio.h>
int main()
{
    int n, row, col;
    printf("\n\n\t Enter No. of layers: ");
    scanf("%d", &n);
    int ar[n][n];
    printf("\n\n\t Filling the Array Elements...\n");
    for(row = 0; row < n; row++)
    {
        for(col = 0; col < n; col++)
        {
            ar[row][col] = row * n + col + 1;
        }
    }
    printf("\n\n\t Printing the array elements...\n\n");
    for(row = 0; row < n; row++)
    {
        for(col = 0; col < n; col++)
        {
            printf("%4d", ar[row][col]);
        }
        printf("\n");
    }
    return 0;
}

