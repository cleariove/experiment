#include<stdio.h>
int main()
{
	int i;
	float m,n,t,sum;
	m=2;
	n=1;
	sum=0;
	for(i=1;i<=20;i++)
	{
		sum=sum+m/n;
		t=m;
		m=m+n;
		n=t;
	}
	printf("sum=%f\n",sum);
	return 0;
}