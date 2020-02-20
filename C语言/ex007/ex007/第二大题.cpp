#include<stdio.h>
void main()
{
	int a[10]={0,9,28,36,47,139,248,290,563,928};
	int *p1,*p2;
	int x,t;
	for(p1=a;p1<(a+10);p1++)
		printf("%5d",*p1);
	printf("\nplease enter a integer:");
	scanf("%d",&x);
	p1=a+5;
	x>*p1?(p2=a+9):(p2=p1,p1=a);
	while(p2-p1>1)
	{
		t=(p2-p1)/2;//可以计算出，中间元素相对于两端元素的位置
		x>*(p1+t)?(p1=p1+t):(p2=p2-t);
	}
	for(p1=a;p1<p2;p1++)
		printf("%5d",*p1);
	printf("%5d",x);
	while(p1<a+10)
	{
		printf("%5d",*p1);
		p1++;
	}
	printf("\n");
}
