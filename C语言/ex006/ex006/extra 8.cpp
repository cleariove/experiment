#include<stdio.h>
void main()
{
	float fun(float x,int y);
	float a,m;
	int n;
	printf("please enter x&n:");
	scanf("%f%d",&a,&n);
	m=fun(a,n);
	printf("%-7.2f\n",m);
}
float fun(float x,int y)
{
	if(y==0)
		return 1;
	if(y==1)
		return (2*x);
	if(y>1)
		return 2*x*fun(x,y-1)-2*(y-1)*fun(x,y-2);
}