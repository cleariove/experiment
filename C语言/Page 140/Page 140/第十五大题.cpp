#include<stdio.h>
#include<math.h>
int main()
{
	float x1,x2,x0,p,q,t;
	printf("enter x1&x2:");
	scanf("%f%f",&x1,&x2);
	p=2*x1*x1*x1-4*x1*x1+3*x1-6;
	q=2*x2*x2*x2-4*x2*x2+3*x2-6;
	if(p*q<0)
	{
		do
		{
		x0=(x1+x2)/2;
		t=2*x0*x0*x0-4*x0*x0+3*x0-6;
		if(t*p<0)
			x2=x0;
		else x1=x0;
		}while(fabs(t)>=1e-5);
	}
	printf("%f",x0);
	return 0;
}