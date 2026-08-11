#include <stdio.h>
void sum();
int main() 
{
    printf("\nGoing To Calculate the Sum of Two Numbers:");
    sum();
    return 0;
}
void sum()
{
    int a, b;
    printf("\nEnter Two Numbers: ");
    scanf("%d %d", &a, &b);

    printf("The sum is: %d", a + b);
}

