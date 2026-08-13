#include<stdio.h>
int main()
{
	int i,sum,fact,n;
	printf("Please Enter the no of Terms:");
	scanf("%d",&n);
	sum=0;
	fact=1;
	for(i=1;i<=n;i++)
	{
		sum=sum+fact;
		printf("\n\t\tCurrent i=%d , fact=%d and sum=%d",2*i-1,fact,sum);
		fact=fact*(2*i)*(2*i+1);
	}
		printf("\n\t\t So The final result of sum=%d",sum);
		return 0;
}

