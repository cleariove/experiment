#include<stdio.h>
#include<math.h>
void main()
{
	int n,a;
	float ��,sum;
	scanf("%d",&a);
    for(n=1,sum=0;n<=a;n++)
	{
	sum=sum+1.0/(n*n);
	}
	��=sqrt(6*sum);
	printf("%f\n",��);
}