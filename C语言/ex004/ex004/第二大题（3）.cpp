#include<stdio.h>
#include<math.h>
void main()
{
	int n;
	float ��,sum;
    for(n=1,sum=0;(n*n)<=10000;n++)
	{
	sum=sum+1.0/(n*n);
	}
	��=sqrt(6*sum);
	printf("��=%f,n=%d\n",��,n-1);
}