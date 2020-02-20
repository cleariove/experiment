#include<stdio.h>
#include<math.h>
int main()
{
	float p1,p2,p3,p4,p5,r1,r2,r3,r5,r0,p;
	p=1000;
	r1=0.0414;
	r2=0.0468;
	r3=0.054;
	r5=0.0585;
	r0=0.0072;
	p1=p*(1+5*r5);
	p2=p*(1+2*r2)*(1+3*r3);
	p3=p*(1+3*r3)*(1+2*r2);
	p4=p*pow(1+r1,5);
	p5=p*pow(1+r0/4,4*5);
	printf("p1=%f\np2=%f\np3=%f\np4=%f\np5=%f\n",p1,p2,p3,p4,p5);
	return 0;
}