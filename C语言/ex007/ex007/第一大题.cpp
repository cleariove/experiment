#include<stdio.h>
void main()
{
	float a[10],sum,aver;
	float *p;
	sum=0;
	printf("please enter ten numbers:");
	for(p=a;p<a+10;p++)
		scanf("%f",p);
	for(p=a;p<a+10;p++)
		sum=sum+*p;
	aver=sum/10;
	printf("average is %.2f\n",aver);
}