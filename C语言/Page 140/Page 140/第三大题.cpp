#include<stdio.h>
int main()
{
	int m,n,i,t,min,max;
	printf("������������������");
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
	printf("�������Ϊ��%d\n",t);
	printf("��С������Ϊ��%d\n",i);
	return 0;
}