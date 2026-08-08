#include<stdio.h>
int main()
{
	int a[5]={1,3,5,7,8};
	int *ptr=(int*)(&a+1);
	printf("%p\n", (&a+1));
	printf("%p\n",a);
	printf("%p\n",(&a));
	printf("%d\n",*(a+1)* *(ptr-2));
	return 0;
}
