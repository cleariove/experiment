#include<stdio.h>
int main()
{
	int d,n;
	n=1;
	for(d=1;d<=9;d++)
	{
		n=2*(n+1);
	}
	printf("sum=%d\n",n);
	return 0;
}