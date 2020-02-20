#include<stdio.h>
int main()
{
	int i,n;
	for(n=1;n<=4;n++)
	{
		for(i=1;i<=-n+4&&i>=0;i++)
			printf(" ");
		for(i=1;i<=2*n-1;i++)
			printf("*");
		printf("\n");
	}
	for(n=1;n<=3;n++)
	{
			for(i=1;i<=n;i++)
				printf(" ");
			for(i=1;i<=-2*n+7;i++)
				printf("*");
			printf("\n");
	}
	return 0;
}