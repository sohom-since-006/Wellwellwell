#include <stdio.h>

int sum(int a, int b);

int main()
{
    int x, y, result;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    result = sum(x, y);

    printf("Sum = %d", result);

    return 0;
}

int sum(int a, int b)
{
    return a + b;
}

