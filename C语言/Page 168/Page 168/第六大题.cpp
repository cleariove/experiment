#include<stdio.h>
int main()
{
	int a[10][10]={},i,j;
	for(i=0;i<=9;i++)
		{
			a[i][0]=1;
			for(j=1;j<=i;j++)
			{
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
	     }
	for(i=0;i<=9;i++)
		for(j=0;j<=9;j++)
		{
			if(j>i) 
				{
					printf("\n");
					break;
			     }
			else printf("%-5d",a[i][j]);
		}
		printf("\n");
	return 0;
}