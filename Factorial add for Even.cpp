#include<stdio.h>
int main()
{
    int i,sum,fact,n;
    printf("Please Enter the no of Terms: ");
    scanf("%d",&n);
    sum=0;
    fact=2;  
    for(i=1;i<=n;i++)
    {
        sum=sum+fact;
        printf("\n\t\tCurrent term=%d! , fact=%d and sum=%d",2*i,fact,sum);
        fact = fact*(2*i+1) * (2*i+2);
    }
    printf("\n\n\t\tSo The final result of sum=%d", sum);
    return 0;
}

