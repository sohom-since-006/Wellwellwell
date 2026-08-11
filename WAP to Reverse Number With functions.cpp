#include <stdio.h>
void number(int *n);
int reverse(int n);
void display(int rev);
int main() {
    int n, rev;
    number(&n);                
    rev = reverse(n);    
    display(rev);             
    return 0;
}
void number(int *n) {
    printf("Enter a Number: ");
    scanf("%d", n);
}
int reverse(int n) {
    int rev = 0, rem;
    while (n != 0) {
        rem = n % 10;
        rev = rev * 10 + rem;
        n = n / 10;
    }
    return rev;
}
void display(int rev) {
    printf("Reversed Number: %d", rev);
}

