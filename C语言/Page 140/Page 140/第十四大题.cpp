#include<stdio.h>
#include<math.h>
int main()
{
	double x1,x2,p,q;
	x2=1.5;
	do{
		x1=x2;
		p=((2*x1-4)*x1+3)*x1-6;
		q=(6*x1-8)*x1+3;
		x2=x1-p/q;
	}while(fabs(x2-x1)>=1e-5);
	printf("%5.2f\n",x2);
	return 0;
}
