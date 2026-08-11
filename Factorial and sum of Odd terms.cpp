#include<stdio.h>
int main()
{
    int n, i, j;
    int odd = 1;
    int fact, sum = 0;
    printf("Enter number of odd terms: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        fact = 1;
        for(j = 1; j <= odd; j++)
            fact *= j;
        sum += fact;
        odd += 2; 
    }
    printf("Sum of factorials = %d", sum);
    return 0;
}

