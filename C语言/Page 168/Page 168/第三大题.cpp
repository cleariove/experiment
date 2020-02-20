#include<stdio.h>
int main()
{
	int a[3][3],i,j,sum;
	sum=0;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
			scanf("%d",&a[i][j]);
	}
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
			printf("%-5d",a[i][j]);
		printf("\n");
	}	
	for(i=0;i<=2;i++)
				sum=sum+a[i][i];
	printf("sum=%d\n",sum);
	return 0;
}