#include<stdio.h>
struct
{
	int year;
	int month;
	int day;
}date;
void main()
{
	int i,a=0,b;
	printf("please enter the date:");
	scanf("%d%d%d",&date.year,&date.month,&date.day);
	if((!(date.year%4)&&date.year%100)||(!(date.year%400)))
		b=29;
	else b=28;
	for(i=1;i<date.month;i++)
	{
		if(i<=7)
		{
			if(i!=2&&i%2) a=a+31;
			else if(i==2) a=a+b;
			else a=a+30;
		}
		else
		{
			if(i%2) a=a+30;
			else a=a+31;
		}
	}
	a=a+date.day;
	printf("The day is %d day\n",a);
}