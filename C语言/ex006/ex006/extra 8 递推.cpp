#include<stdio.h>
void main()
{
	float fun(float x,int y);
	float a,b;
	int n;
	printf("please enter a&n:");
	scanf("%f%d",&a,&n);
	b=fun(a,n);
	printf("%-7.2f\n",b);
}
float fun(float x,int y)
{
	int i=2;
	float a,b,c;
	a=1;
	b=2*x;
	while(i<=y&&y>=2)
	{
		c=2*x*b-2*(i-2)*a;
		a=b;
		b=c;
		i++;
	}
	if(y>=2) return c;
	else if(y==1) return b;
	else return a;
}