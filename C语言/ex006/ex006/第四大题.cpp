#include<stdio.h>
void main()
{
	int combinNum(int m,int n);
	int a,b,c;
	int t;
	printf("This is a combined number computation program.\nplease input two numbers:");
	scanf("%d%d",&a,&b);
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	c=combinNum(a,b);
	printf("the result is %d\n",c);
}
int combinNum(int m,int n)
{
	int factorial(int x);
	int c;
	c=factorial(m)/(factorial(n)*factorial(m-n));
	return (c);
}
int factorial(int x)
{
	int n,sum;
	sum=1;
	if(x==0)
		return 1;
	else 
	{
		for(n=1;n<=x;n++)
			sum=sum*n;
		return sum;
	}
}