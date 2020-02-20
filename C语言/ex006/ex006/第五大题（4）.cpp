#include<stdio.h>
int x,y;
void main()
{
	void gcd(int m,int n);
	void mul(int m,int n);
	int a,b;
	printf("input two numbers:");
	scanf("%d%d",&a,&b);
	gcd(a,b);
	mul(a,b);
	printf("The gcd is %d.\nThe mul is %d.\n",x,y);
}
void gcd(int m,int n)
{
	x=(m<n?m:n);
	while(x>0&&(m%x!=0||n%x!=0))
		x--;
}
void mul(int m,int n)
{
	y=(m*n)/x;
}