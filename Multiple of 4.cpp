#include<stdio.h>
int main(){
	int n;
	printf("Enter A Number:");
	scanf("%d",&n);
	if ((n&3)==0)
	printf("%d Is a Multiple of 4\n" ,n);
	else 
	printf("%d Is not a Multiple of 4\n", n);
	return 0;
}
