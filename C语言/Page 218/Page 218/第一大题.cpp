#include<stdio.h>
int main()
{
	int multiple(int x,int y);
	int divisor(int x,int y);
	int a,b;
	printf("����������������");
	scanf("%d%d",&a,&b);
	printf("��С������Ϊ��%d\n�������Ϊ��%d\n",multiple(a,b),divisor(a,b));
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