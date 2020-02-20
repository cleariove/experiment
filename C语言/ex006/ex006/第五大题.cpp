#include<stdio.h>
void main()
{
	int gcd(int m,int n);
	int mul(int m,int n,int x);
	int a,b,c,d;
	printf("input two numbers:");
	scanf("%d%d",&a,&b);
	c=gcd(a,b);
	d=mul(a,b,c);
	printf("The gcd of the two numbers is %d\nThe mul of the two numbers is %d\n",c,d);
}
int gcd(int m,int n)
{
	int i;
	i=(m<n?m:n);
	while((m%i!=0||n%i!=0)&&i>=1)
		i--;
	return (i);
}
int mul(int m,int n,int x)
{
	x=(m*n)/x;
	return (x);
}