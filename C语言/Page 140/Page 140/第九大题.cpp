#include<stdio.h>
int main()
{
	int n,m,sum;
	sum=0;
	for(n=1;n<=1000;n++)
	{
		for(m=1;m<n;m++)
		{
			if(n%m==0)
			{
				sum=sum+m;
			}
		}
		if(sum==n)
		{
			printf("%d,its factors are ",sum);
			for(m=1;m<n;m++)
				if(n%m==0)
					printf("%d ",m);
			printf("\n");
		}
		sum=0;
	}
	return 0;
}