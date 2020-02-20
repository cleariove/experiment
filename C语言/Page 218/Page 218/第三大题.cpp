#include<stdio.h>
#include<math.h>
int main()
{
	void prime_number(int x);
	int a;
	printf("input a intefer number:");
	scanf("%d",&a);
	prime_number(a);
	return 0;
}
void prime_number(int x)
{
	int i;
	int k;
	k=sqrt(x*1.0);
	for(i=2;i<=k;i++)
	{
		if(x%k!=0) ;
		else break;
	}
	if(i==k+1)
		printf("%d is a prime number.\n",x);
	else
		printf("%d is not a prime number.\n",x);
}