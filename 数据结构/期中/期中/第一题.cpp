#include<stdio.h>
#include<stdlib.h>

int func(int n)
{
	int i = 0;
	if(n >= 100)
	{
		i += (int)n/100;
		n = n %100;
	}
	if(n >= 50)
	{
		i += (int)n/50;
		n = n %50;
	}
	if(n >= 10)
	{
		i += (int)n/10;
		n = n %10;
	}
	if(n >= 5)
	{
		i += (int)n/5;
		n = n %5;
	}
	if(n >= 2)
	{
		i += (int)n/2;
		n = n %2;
	}
	if(n >= 1)
	{
		i += (int)n/1;
		n = n %1;
	}
	return i;
}

int main()
{
	int n,x,i,j;
	while(1)
	{
		scanf("%d",&n);
		if(n <= 0 || n >= 100)
			break;
		else
			for(i = 1,j = 0;i <= n;i++)
			{
				scanf("%d",&x);
				if(x < 0)
					exit (0);
				j += func(x);
			}
		printf("%d\n",j);
	}
	system("pause");
	return 0;
}