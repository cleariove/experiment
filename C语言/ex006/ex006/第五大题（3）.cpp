#include<stdio.h>
void main()
{
	int gcd(int m,int n);
	int mul(int m,int n,int x);
	int a,b,c,d;
	int t;
	printf("input two numbers:");
	scanf("%d%d",&a,&b);
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	c=gcd(a,b);
	d=mul(a,b,c);
	printf("The gcd of the two numbers is %d.\nThe mul of the two numbers is %d.\n",c,d);
}
int gcd(int m,int n)
{
	if(m%n==0)
		return n;
	else gcd(n,m%n);
}
int mul(int m,int n,int x)
{
	x=(m*n)/x;
	return (x);
}