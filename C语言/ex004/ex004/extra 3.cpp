#include<stdio.h>
#include<math.h>
void main()
{
	int n,x,m,k;
	float a;
	printf("请输入一个正整数：");
	scanf("%d",&n);
	printf("%d=",n);
    for(k=2;k<=n;k++)
	{
		a=k;
		x=sqrt(a);
		for(m=2;m<=x+1;m++)
		{
			if(k==2||k%m!=0);
			else break;
		    while(n!=1)
			{
				if(n%k==0)
					{
						printf("%d*",k);
						n=n/k;
				     }
				else break;
			}
		}
	}
	printf("\b \n");
}