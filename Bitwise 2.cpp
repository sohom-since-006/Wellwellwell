#include<stdio.h>
int main(){
	int n,i;
	printf("Enter the Number and bit Position:");
	scanf("%d %d",&n, &i);
	n|=(1<<i);
	printf("Number After setting %d-th bit is: %d \n", i , n);
	return 0;
}
