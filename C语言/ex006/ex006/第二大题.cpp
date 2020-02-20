#include<stdio.h>
int main()
{
	int computNum(int num);
	int num,sum;
	printf("please enter a integer:");
	scanf("%d",&num);
	sum=computNum(num);
	printf("The sum of all the numbers are %d\n",sum);
	return 0;
}
int computNum(int num)
{
	int c;
	c=0;
	while(num>0)
	{
		c=c+num%10;
		num=num/10;
	}
	return (c);
}