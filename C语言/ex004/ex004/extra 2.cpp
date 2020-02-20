#include<stdio.h>
void main()
{
	int i,j,n;
	n=0;
	for(i=1;i<=10;i++)
	{
		for(j=1;i>j;j++)
		{
			printf("<%d,%d>",i,j);
			n=n+1;
			if(n%5==0)
				printf("\n");
		}
	}
}