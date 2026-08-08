#include <stdio.h>

int sum();

int main()
{
    int result;

    result = sum();

    printf("Sum = %d", result);

    return 0;
}

int sum()
{
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    return a + b;
}

