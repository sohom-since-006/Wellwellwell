#include <stdio.h>

void number(int *n);
long long factorial(int n);
void display(int n, long long fact);

int main() {
    int n;
    long long fact;

    number(&n);         
    fact = factorial(n); 
    display(n, fact);    

    return 0;
}
void number(int *n) {
    printf("Enter a Number: ");
    scanf("%d", n);
}

long long factorial(int n) {
    long long fact = 1;

    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    return fact;
}

void display(int n, long long fact) {
    printf("Factorial of %d is %lld", n, fact);
}
