//WAP to Compute and print Quotient and Remainder
#include<stdio.h>
int main(){
	int a,b;
	printf("Enter Dividend and Divisor:");
	scanf("%d %d",&a,&b);
	printf("Quotient:%d\n",a/b);
	printf("Remainder:%d\n", a%b);
	return 0;
}
