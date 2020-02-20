#include<stdio.h>
#include<math.h>
float x1,x2;
void main()
{
	void solution(float a,float b,float c);
	float a,b,c;
	printf("input three numbers:");
	scanf("%f%f%f",&a,&b,&c);
	solution(a,b,c);
}
void solution(float a,float b,float c)
{
	float disc,p,q;
	disc=b*b-4*a*c;
	p=b/(2*a);
	if(disc>0)
	{
		q=(sqrt(disc))/(2*a);
		x1=-p-q;
		x2=q-p;
		printf("x1=%-7.2f\nx2=%-7.2f\n",x1,x2);
	}
	else if(disc==0)
	{
		x1=-p;
		printf("x=%-7.2f\n",x1);
	}
	else
	{
		q=(sqrt(-disc))/(2*a);
		printf("x1=%-7.2f+%-7.2fi\nx2=%-7.2f-%-7.2fi\n",-p,q,-p,q);

	}
}