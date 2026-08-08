#include<stdio.h>
int main()
{
    char str[50];
    int i, len=0;
	printf("Enter a String:");
	scanf("%d",&str);
	gets(str);
	for(i = 0; str[i]!=0; i++)
		(len++);
	
	printf("The Lenghth Of the string is :", len);
	return 0;
}
