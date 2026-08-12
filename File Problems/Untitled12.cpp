#include<stdio.h>
int main()
{
    FILE *f = fopen("file.txt", "a+"); 
    if (f == NULL)
        printf("Error Opening file\n");
		
