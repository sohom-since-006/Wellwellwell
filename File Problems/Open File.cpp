#include<stdio.h>
int main()
{
    FILE *f = fopen("fnew.txt", "r+"); 
    if (f == NULL)
        printf("File Not Found\n");
    else
        printf("Opened\n");
        fclose(f);
    return 0;
}

