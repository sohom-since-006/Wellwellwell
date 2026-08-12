#include<stdio.h>
int main()

{
	int a=-1,b=10;
	if(++a && ++b)
		printf("In IF %d",a,b);
	else
		printf("In Else %d",a,b);
		return 0;
	
}

