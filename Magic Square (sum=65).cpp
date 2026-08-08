#include<stdio.h>
int main(){
	int i,r,c,n,s=0;
	printf("\n\n\t\tEnter The odd Dimension of the matrix...");
	scanf("%d",&n);
	printf("\n\n\t\t Pre Calculated Magic Sum is %d...\n",n*(n*n+1)/2);
	r=1 , c=(n+1)/2;
	
	for(i=1,i<=n*n;i++)
	{
		a[r][c]=i;r--;c++;
		if(r<1&&c>n)
		{r=r+2;c=c-1;}
		else if(r<1) r=n;
		else if(c>n) c=1;
		else if (a[r][c]!=0) { r=r+2;c=c-1;}	
	}
	printf("\n\n Printing The array Elements...\n\n");
	for (r=1;r<=n;r++)
	{
		printf("\n\n\t");
		for(c=1;c<=n;c++)
		{
			printf("%4d",a[r][c]);
			if(r==c) s=s+a[r][c];
		}
	}
	return 0;
}
		
