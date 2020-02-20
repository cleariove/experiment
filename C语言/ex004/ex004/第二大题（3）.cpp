#include<stdio.h>
#include<math.h>
void main()
{
	int n;
	float ¦Ð,sum;
    for(n=1,sum=0;(n*n)<=10000;n++)
	{
	sum=sum+1.0/(n*n);
	}
	¦Ð=sqrt(6*sum);
	printf("¦Ð=%f,n=%d\n",¦Ð,n-1);
}