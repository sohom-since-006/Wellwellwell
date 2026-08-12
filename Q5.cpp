//WAP to swap two Numbers
#include<stdio.h>
int main(){
	int a,b,temp;
	printf("Enter Two Numbers:");
	scanf("%d %d", &a , &b);
	temp = a;
	b = a;
	b = temp;
	printf("After Swapping a = %d , b = %d\n",a,b);
	return 0;
	
}
