#include<stdio.h>
int main()
{
	void insert(char a[],int n);
	char a[4];
	int b,n;
	printf("please input four digits:");
	scanf("%d",&b);
	insert(a,b);
	for(n=3;n>=0;n--)
		printf("%c ",a[n]);
	return 0;
}
void insert(char a[],int n)
{
	int i;
	for(i=0;i<4;i++)
	{
		a[i]=n%10+48;
		n=n/10;
	}
}