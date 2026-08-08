#include<stdio.h>
int main(){
	int arr[]={11,22,33,44,55};
	int i;
	for(i=0;i<5;i++)
	{
		printf("arr[%d]:%d add=%p\n",i,arr[i],&arr[i]);
		printf("arr[%d]: %d\n",i, *(arr+i));
		printf("...............\n");
	}
	return 0;
}
