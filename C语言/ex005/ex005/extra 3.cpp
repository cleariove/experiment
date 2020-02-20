#include<stdio.h>
#define N 5
void main()
{
	int multiple(int array[]);
	int divisor(int array[]);
	int a[N];
	int p,q,i;
	printf("please enter 5 numbers:");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	p=multiple(a);
	printf("最小公倍数为%d\n",p);
	q=divisor(a);
	printf("最大公因数为%d\n",q);
}

int multiple(int array[])
{
	int i,t,k;
	t=array[0];
	for(i=1;i<5;i++)
	{
		k=t;
		t=(t>array[i]?t:array[i]);
		while(t%k!=0||t%array[i]!=0)
			t++;
	}
	return (t);
}

int divisor(int array[])
{
	int k,t,i;
	t=array[0];
	for(i=1;i<5;i++)
	{
		k=t;
		t=(t<array[i]?t:array[i]);
		while(k%t!=0||array[i]%t!=0)
			t--;
	}
	return (t);
}