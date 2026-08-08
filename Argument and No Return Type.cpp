#include <stdio.h>

void sum(int a, int b);

int main()
{
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    sum(x, y);

    return 0;
}

void sum(int a, int b)
{
    printf("Sum = %d", a + b);
}

