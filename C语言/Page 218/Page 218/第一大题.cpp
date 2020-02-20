#include<stdio.h>
int main()
{
	int multiple(int x,int y);
	int divisor(int x,int y);
	int a,b;
	printf("请输入两个整数：");
	scanf("%d%d",&a,&b);
	printf("最小公倍数为：%d\n最大公因数为：%d\n",multiple(a,b),divisor(a,b));
	return 0;
}
int multiple(int x ,int y)
{
	int k;
	k=(x>y?x:y);
	while(!(k%x==0&&k%y==0))
		k++;
	return (k);
}
int divisor(int x,int y)
{
	int k;
	k=(x<y?x:y);
	while((x%k!=0||y%k!=0)&&k>0)
		k--;
	return (k);
}