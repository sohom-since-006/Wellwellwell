#include<stdio.h>

void square(int n);
void _square(int *n);


void square (int n){
	n = n * n ;
	printf("Square of Your Number is %d\n",n);
}

void _square(int*n){
	*n = (*n) * (*n);
	printf("The Square of Your Number is %d\n",*n);
}
int main (){
	int num;
	printf("Enter no:");
	scanf("%d",&num);
	square(num);
	printf("Your Number is :%d",num);
	_square(&num);
	printf("Your Number is :%d",num);
	return 0;
}

