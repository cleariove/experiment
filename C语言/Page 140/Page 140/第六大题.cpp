#include<stdio.h>
int main()
{
	int n;
	double sum,t;/*范围大小一定要注意！！！！！！*/
	n=20;
	sum=0;
	t=1;
	for(n=1;n<=20;n++)
	{
		t=t*n;
		sum=sum+t;
	}
	printf("sum=%e\n",sum);
	return 0;
}