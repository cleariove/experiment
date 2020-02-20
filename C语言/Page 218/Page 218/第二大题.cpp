#include<stdio.h>
#include<math.h>
float p,q,x1,x2,disc;
int main()
{
	void minus(float a,float b,float c);
	void zero(float a,float b,float c);
	void positive(float a,float b,float c);
	float a,b,c,disc;
	printf("input a,b,c:");
	scanf("%f%f%f",&a,&b,&c);
    disc=b*b-4*a*c;	
	if(disc>0)
		positive(a,b,c);
	else if(disc==0)
		zero(a,b,c);
	else 
		minus(a,b,c);
}
void positive(float a,float b,float c)
{
	x1=(-b+sqrt(disc))/(2*a);
	x2=(-b-sqrt(disc))/(2*a);
	printf("x1=%7.2f,x2=%7.2f\n",x1,x2);
}
void zero(float a,float b,float c)
{
	x1=-b/2*a;
	printf("x=%7.2f\n",x1);
}
void minus(float a,float b,float c)
{
	printf("no root\n");
}