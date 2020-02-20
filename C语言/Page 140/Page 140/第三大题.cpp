#include<stdio.h>
int main()
{
	int m,n,i,t,min,max;
	printf("请输入两个正整数：");
	scanf("%d%d",&m,&n);
	min=(m>n?n:m);
	max=(m>n?m:n);
	for(i=1;i<=min;i++)
	{
		if(m%i==0&&n%i==0)
			t=i;
	}
	for(i=max;i%m!=0||i%n!=0;i++)
	{}
	printf("最大公因数为：%d\n",t);
	printf("最小公倍数为：%d\n",i);
	return 0;
}