#include<stdio.h>
int main(){
	int n;
	printf("Enter A Number:");
	scanf("%d",&n);
	if (n>0 && (n&(n-1)==0))
	printf("%d Is Power of 2\n" ,n);
	else 
	printf("%d Is not a Power Of 2\n", n);
	return 0;
}
