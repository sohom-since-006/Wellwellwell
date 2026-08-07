#include<stdio.h>
int main(){
	int n,i;
	printf("Enter the Number and bit Position:");
	scanf("%d %d",&n, &i);
	int bit = (n>>i) & 1;
	printf("For getting the %d - th Bit is: %d \n", i , bit);
	return 0;
}
