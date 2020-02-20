#include<stdio.h>
int main()
{
	int a,b,c,max;
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) max=a;
	else max=b;
	if(max<c) max=c;
	printf("最大值为%d\n",max);
	return 0;
}