#include<stdio.h>
int main()
{
	double a,b,c,sum;/*������˫���ȣ������������*/
	int k;
	a=0;
	b=0;
	c=0;
	sum=0;
	for(k=1;k<=100;k++)
		a=a+k;
    for(k=1;k<=50;k++)
		b=b+k*k;		
	for(k=1;k<=10;k++)
        c=c+1.0/k;
	sum=a+b+c;
	printf("sum=%lf\n",sum);
	return 0;
}